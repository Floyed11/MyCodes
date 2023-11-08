#include <stdio.h>
#include <stdbool.h>

int isTmax(int x)
{
  return !(~((x ^ (x + 1)) + 1)) & (!!(~x));
}

int flag(int x)
{
  return x > 0;
}

// int main(){

//   bool flag=true;
//   scanf("%d",&flag);
//   printf("%",flag);
//   int a,sum=0;
//   char str[10]={"home"};
//   scanf("%d",&a);
//   switch(a)
//     case 1:
//     sum++;
//     case 2:
//     sum++;
//     default:
//     sum++;
//   }
//   printf("%d\n",sum);
//   printf("%c",str[4]);
//   return 0;

// }
// int g=16;
// int main(){
//   int k=++g;
//   printf("%d %d\n",k,g);
//   return 0 ;
// }
int main()
{
  // double f=1.000000001;
  // printf("%lf\n",f);
  // return 0;
  // int x;
  // scanf("%d", &x);
  // printf("%d\n",isTmax(x));
  // for(int i=0;i<5;i++) printf(" ");
  // printf("%d", x);
  // void *mm_realloc(void *ptr, size_t size)
  // {
  //   // 如果 ptr == NULL 直接分配
  //   if (ptr == NULL)
  //     return mm_malloc(size); // 如果 size == 0 就释放
  //   else if (size == 0)
  //   {
  //     mm_free(ptr);
  //     return NULL;
  //   }

  //   size_t asize = align_size(size), old_size = CRT_BLKSZ(ptr);
  //   size_t mv_size = MIN(asize, old_size);
  //   char *oldptr = ptr;
  //   char *newptr;
  //   if (old_size == asize)
  //     return ptr;
  //   size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(ptr)));
  //   size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(ptr)));
  //   size_t next_size = NEXT_BLKSZ(ptr);
  //   char *next_bp = NEXT_BLKP(ptr);
  //   size_t total_size = old_size;
  //   if (prev_alloc && !next_alloc && (old_size + next_size >= asize))
  //   { // 后空闲
  //     total_size += next_size;
  //     delete_free_block(next_bp);
  //     PUT(HDRP(ptr), PACK(total_size, ALLOCATED));
  //     PUT(FTRP(ptr), PACK(total_size, ALLOCATED));
  //     place(ptr, total_size);
  //   }
  //   else if (!next_size && asize >= old_size)
  //   { // 如果后部是结尾块，则直接 extend_heap
  //     size_t extend_size = asize - old_size;
  //     if ((long)(mem_sbrk(extend_size)) == -1)
  //       return NULL;
  //     PUT(HDRP(ptr), PACK(total_size + extend_size, ALLOCATED));
  //     PUT(FTRP(ptr), PACK(total_size + extend_size, ALLOCATED));
  //     PUT(HDRP(NEXT_BLKP(ptr)), PACK(0, ALLOCATED));
  //     place(ptr, asize);
  //   }
  //   else
  //   { // 直接分配
  //     newptr = mm_malloc(asize);
  //     if (newptr == NULL)
  //       return NULL;
  //     memcpy(newptr, ptr, MIN(old_size, size));
  //     mm_free(ptr);
  //     return newptr;
  //   }
  //   return ptr;
  // }
  int n = -12431;
  int x = (n = flag(n));
  printf("%d", x);
  return 0;
}