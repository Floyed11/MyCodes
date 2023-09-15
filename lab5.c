/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 *
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

// #include "mm.h"
// #include "memlib.h"

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT - 1)) & (~0x7))

/* get or set the value of a word at address p */
#define GET(p) (*(unsigned int *)(p))
#define PUT(p, value) ((*(unsigned int *)(p)) = (unsigned int)(value))

/* get the size or allocated number at address p */
#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLO(p) (GET(p) & 0x1)

/* get header or footer part at address p */
#define HDRP(p) ((char *)(p)-WSIZE)
#define FTRP(p) ((char *)(p) + GET_SIZE(HDRP(p)) - (2 * WSIZE))

/* get predecessor and successor address from address p through pointer */
#define PREDP(p) (char *)(long)(GET((char *)p))
#define SUCCP(p) ((char *)(long)GET((char *)(p) + WSIZE))

/* reach next and previous blocks from address p through block size */
#define NEXT_BLKP(p) ((char *)(p) + GET_SIZE(((char *)(p)-WSIZE)))
#define PREV_BLKP(p) ((char *)(p) - GET_SIZE(((char *)(p) - (2 * WSIZE))))

/* combine size and bit representing allocation */
#define PACK(size, alloc) ((size) | (alloc))

/* size_t and pointer aligned size */
#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))
#define PTR_SIZE (ALIGN(2 * sizeof(size_t)))

/* the minimum size of block */
#define MINSIZE (6 * WSIZE)

/* word size */
#define WSIZE 4

/* extend the heap at this size */
#define INITSIZE (1 << 12)

/* private global variables */
static char *heap_root;

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
// team_t team = {
//     /* Team name */
//     "ateam",
//     /* First member's full name */
//     "Harry Bovik",
//     /* First member's email address */
//     "bovik@cs.cmu.edu",
//     /* Second member's full name (leave blank if none) */
//     "",
//     /* Second member's email address (leave blank if none) */
//     ""
// };

/* insert block at address bp to the head of the heap */
void insert(void *bp)
{
    /* if the heap is empty */
    if (heap_root == NULL)
    {
        PUT(bp, NULL);
        PUT(((char *)(bp) + WSIZE), NULL);
        heap_root = bp;
    }
    else
    {
        PUT(((char *)(bp) + WSIZE), heap_root);
        PUT(heap_root, bp);
        PUT(bp, NULL);
        heap_root = bp;
    }
    return;
}

void delete(void *bp)
{
    /* it is the only block */
    if (PREDP(bp) == NULL && SUCCP(bp) == NULL)
    {
        heap_root = NULL;
        return;
    }
    /* is the last block */
    else if (SUCCP(bp) == NULL)
    {
        PUT((char *)(PREDP(bp)) + WSIZE, NULL);
        return;
    }
    /* is the first block */
    else if (PREDP(bp) == NULL)
    {
        heap_root = SUCCP(bp);
        PUT(SUCCP(bp), NULL);
        return;
    }
    else
    {
        PUT((char *)(PREDP(bp)) + WSIZE, SUCCP(bp));
        PUT(SUCCP(bp), PREDP(bp));
        return;
    }
    return;
}

/* coalesce adjacent blocks if possible */
static void *coalesce(void *bp)
{
    size_t pred_alloc = GET_ALLO(HDRP(PREV_BLKP(bp)));
    size_t succ_alloc = GET_ALLO(HDRP(NEXT_BLKP(bp)));
    size_t size = GET_SIZE(HDRP(bp));

    /* both blocks are allocated */
    if (pred_alloc && succ_alloc)
    {
        insert(bp);
        return bp;
    }
    /* predecessor is allocated while successor is not allocated */
    else if (pred_alloc && (!succ_alloc))
    {
        delete (NEXT_BLKP(bp));
        size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
        PUT(HDRP(bp), PACK(size, 0));
        PUT(FTRP(bp), PACK(size, 0));
        insert(bp);
        return bp;
    }
    /* predecessor is not allocated while successor is allocated */
    else if ((!pred_alloc) && (succ_alloc))
    {
        delete (PREV_BLKP(bp));
        size += GET_SIZE(HDRP(PREV_BLKP(bp)));
        PUT(FTRP(bp), PACK(size, 0));
        PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
        bp = PREV_BLKP(bp);
        insert(bp);
        return bp;
    }
    /* both are not allocated */
    else
    {
        delete (PREV_BLKP(bp));
        delete (NEXT_BLKP(bp));
        size = size + GET_SIZE(HDRP(PREV_BLKP(bp))) + GET_SIZE(HDRP(NEXT_BLKP(bp)));
        PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
        PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
        bp = PREV_BLKP(bp);
        insert(bp);
        return bp;
    }
    return NULL;
}

/* extend the heap by #words */
static void *extend_heap(int words)
{
    char *bp;
    size_t size;
    if ((words % 2) == 1)
        size = (words + 1) * WSIZE;
    else
        size = words * WSIZE;

    if ((long)(bp = mem_sbrk(size)) == -1)
        return NULL;
    
    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    PUT((char *)FTRP(bp) + WSIZE, PACK(0, 1));
    return coalesce(bp);
}

/*
 * mm_init - initialize the malloc package.
 */
int mm_init(void)
{
    if ((long)(heap_root = mem_sbrk(4 * WSIZE)) == -1)
        return -1;
    PUT(heap_root, 0);
    PUT(heap_root + WSIZE, PACK((2 * WSIZE), 1));
    PUT(heap_root + (2 * WSIZE), PACK((2 * WSIZE), 1));
    PUT(heap_root + (3 * WSIZE), PACK(0, 1));
    heap_root = NULL;

    if (extend_heap(INITSIZE / WSIZE) == NULL)
        return -1;

    return 0;
}

/* place a new block of #size at address bp */
void place(void *bp, int size)
{
    int bsize = GET_SIZE(HDRP(bp));
    delete (bp);
    if ((bsize - size) < MINSIZE)
    {
        PUT(HDRP(bp), PACK(bsize, 1));
        PUT(FTRP(bp), PACK(bsize, 1));
    }
    else
    {
        PUT(HDRP(bp), PACK(size, 1));
        PUT(FTRP(bp), PACK(size, 1));
        bp = NEXT_BLKP(bp);
        PUT(HDRP(bp), PACK(bsize - size, 0));
        PUT(FTRP(bp), PACK(bsize - size, 0));
        insert(bp);
    }
    return;
}

/* find an empty block with #size */
char *find_fit(int size)
{
    char *fp = heap_root;
    while ((fp != NULL) && (GET_SIZE(HDRP(fp)) < size))
    {
        fp = SUCCP(fp);
    }
    return fp;
}

/*
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size)
{
    int newsize = ALIGN(size + PTR_SIZE);
    if (newsize < MINSIZE)
        newsize = MINSIZE;
    char *bp;
    if (size == 0)
        return NULL;
    bp = find_fit(newsize);
    if (bp != (char *)NULL)
    {
        place(bp, newsize);
        return bp;
    }
    else
    {
        void *p = extend_heap(newsize / WSIZE);
        if (p == (void *)-1)
            return NULL;
        else
        {
            bp = (char *)p;
            place(bp, newsize);
            return bp;
        }
    }
    return NULL;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr)
{
    if (ptr == NULL)
        return;
    int size = GET_SIZE(HDRP(ptr));
    PUT(HDRP(ptr), PACK(size, 0));
    PUT(FTRP(ptr), PACK(size, 0));
    coalesce(ptr);
    return;
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size)
{
    void *oldptr = ptr;
    void *newptr;
    size_t copySize;
    size_t asize = ALIGN(size + PTR_SIZE);

    /* when ptr is NULL */
    if (oldptr == NULL)
        return mm_malloc(size);
    /* when size equals to zero, return NULL */
    if (size == 0)
    {
        mm_free(oldptr);
        return NULL;
    }

    /* how to extend the size of old block remained to be completed */
    newptr = mm_malloc(asize);
    copySize = GET_SIZE(HDRP(oldptr));
    if (size < copySize)
        copySize = size;
    memcpy(newptr, oldptr, copySize);
    mm_free(oldptr);
    return newptr;
}
