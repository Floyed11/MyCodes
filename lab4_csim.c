/* this is written by 林童奕凡 10225501422 */

//#include "cachelab.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#define ADDR_BITS 64
#define type_l unsigned long long
// #define type_l_scan "%lx"

long hit_count = 0, miss_count = 0, eviction_count = 0;
int vflag = 0;

typedef struct cache_line_define
{
    int valid;
    type_l tag;
    int *block;
    long LRU;
} type_cache_line;

typedef struct set_define
{
    type_cache_line *line;
} type_set;

typedef struct cache_define
{
    type_set *sets;
} type_cache;

type_cache init_cache(type_cache cache, long s, long E, long b)
{
    cache.sets = (type_set *)malloc(sizeof(type_set) * (1 << s));
    for (long i = 0; i < (1 << s); i++)
    {
        cache.sets[i].line = (type_cache_line *)malloc(sizeof(type_cache_line) * E);
        for (long j = 0; j < E; j++)
        {
            cache.sets[i].line[j].valid = 0;
            cache.sets[i].line[j].tag = 0;
            cache.sets[i].line[j].block = (int *)malloc(sizeof(int) * (1 << b));
            cache.sets[i].line[j].LRU = 0;
        }
    }
    return cache;
}

void prt_cache(type_cache cache, long s, long E, long b){
    for (long i = 0; i < (1 << s); i++){
        for (long j = 0; j < E;j++){
            printf("%d %ld ", cache.sets[i].line[j].valid, i);
        }
    }
    printf("\n");
    return;
}
long B2D(long bin_num)
{
    long dec_num = 0;
    long base = 1;
    while (bin_num > 0)
    {
        dec_num += (bin_num % 10) * base;
        bin_num /= 10;
        base *= 2;
    }
    return dec_num;
}

long get_set(type_l addr, int s, int b)
{
    return B2D((addr >> b) & ((1 << s) - 1));
}

type_l get_tag(type_l addr, int s, int b)
{
    return addr >> (s + b);
}

long get_block(type_l addr, int s, int b)
{
    return B2D(addr & ((1 << b) - 1));
}

type_cache load(type_cache cache, type_l addr, long size, long s, long E, long b)
{
    long set_index = (addr >> b) & ((1 << s) -1);
    type_l tag = get_tag(addr, s, b);
    //printf("%ld\n",set_index);
    // int block_index = get_block(addr, s, b);
    for (long i = 0; i < E; i++)
    {
        if (cache.sets[set_index].line[i].valid == 1 && cache.sets[set_index].line[i].tag == tag)
        {
            hit_count++;
            cache.sets[set_index].line[i].LRU = 0;
            for (long j = 0; j < E; j++)
            {
                if (j != i)
                {
                    cache.sets[set_index].line[j].LRU++;
                }
            }
            if (vflag)
                printf("hit ");
            return cache;
        }
    }
    // 未命中的情形
    miss_count++;
    for (long i = 0; i < E; i++)
    {
        if (cache.sets[set_index].line[i].valid == 0)
        {
            cache.sets[set_index].line[i].valid = 1;
            cache.sets[set_index].line[i].tag = tag;
            cache.sets[set_index].line[i].LRU = 0;
            for (int j = 0; j < E; j++)
            {
                if (j != i)
                {
                    cache.sets[set_index].line[j].LRU++;
                }
            }
            if (vflag)
                printf("miss ");
            return cache;
        }
    }
    // 需要驱逐的情形
    eviction_count++;
    long max_LRU = 0;
    long max_index = 0;
    for (long i = 0; i < E; i++)
    {
        if (cache.sets[set_index].line[i].LRU > max_LRU)
        {
            max_LRU = cache.sets[set_index].line[i].LRU;
            max_index = i;
        }
    }
    cache.sets[set_index].line[max_index].tag = tag;
    cache.sets[set_index].line[max_index].LRU = 0;
    for (long j = 0; j < E; j++)
    {
        if (j != max_index)
        {
            cache.sets[set_index].line[j].LRU++;
        }
    }
    if (vflag)
        printf("miss eviction ");
    return cache;
}

type_cache store(type_cache cache, type_l addr, long size, long s, long E, long b)
{
    long set_index = (addr >> b) & ((1 << s) -1);
    type_l tag = get_tag(addr, s, b);
    //printf("%ld\n",set_index);
    // int block_index = get_block(addr, s, b);
    for (long i = 0; i < E; i++)
    {
        if (cache.sets[set_index].line[i].valid == 1 && cache.sets[set_index].line[i].tag == tag)
        {
            hit_count++;
            cache.sets[set_index].line[i].LRU = 0;
            for (long j = 0; j < E; j++)
            {
                if (j != i)
                {
                    cache.sets[set_index].line[j].LRU++;
                }
            }
            if (vflag)
                printf("hit ");
            return cache;
        }
    }
    long max_LRU = -1;
    long max_index = -1;
    for (long i = 0; i < E; i++)
    {
        if (cache.sets[set_index].line[i].valid == 0 && cache.sets[set_index].line[i].LRU > max_LRU)
        {
            max_LRU = cache.sets[set_index].line[i].LRU;
            max_index = i;
        }
    }
    if (max_index != -1)
    {
        miss_count++;
        cache.sets[set_index].line[max_index].valid = 1;
        cache.sets[set_index].line[max_index].tag = tag;
        cache.sets[set_index].line[max_index].LRU = 0;
        for (long j = 0; j < E; j++)
        {
            if (j != max_index)
            {
                cache.sets[set_index].line[j].LRU++;
            }
        }
        if (vflag)
            printf("miss ");
        return cache;
    }
    // 未命中的情形
    miss_count++;
    eviction_count++;
    max_index = 0;
    max_LRU = 0;
    for (long i = 0; i < E; i++)
    {
        if (cache.sets[set_index].line[i].LRU > max_LRU)
        {
            max_LRU = cache.sets[set_index].line[i].LRU;
            max_index = i;
        }
    }
    cache.sets[set_index].line[max_index].tag = tag;
    cache.sets[set_index].line[max_index].LRU = 0;
    for (long j = 0; j < E; j++)
    {
        if (j != max_index)
        {
            cache.sets[set_index].line[j].LRU++;
        }
    }
    //prt_cache(cache, s,E,b);
    if (vflag)
        printf("miss eviction");
    return cache;
}

int main(int argc, char *argv[])
{
    long opt, s = 0, E = 0, b = 0;
    // int m = ADDR_BITS;
    FILE *fp = NULL;
    const char *FileName;
    while ((opt = getopt(argc, argv, "hvs:E:b:t:")) != -1)
    {
        switch (opt)
        {
        case 's':
            s = atoi(optarg);
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            break;
        case 't':
            FileName = optarg;
            break;
        case 'v':
            vflag = 1;
        default:
            break;
        }
    }
    // printf("%s\n", FileName);
    fp = fopen(FileName, "r");
    if (fp == NULL)
    {
        printf("reading error\n");
        return 0;
    }
    type_cache cache;
    cache = init_cache(cache, s, E, b);
    char option;
    type_l addr;
    long size;
    while (fscanf(fp, "%c%llx,%ld", &option, &addr, &size) != EOF)
    {
        // fflush(stdin);
        // printf("%c\n",option);
        if (option == 'I')
            continue;
        switch (option)
        {
        case 'L':
            if (vflag)
                printf("%c %llx,%ld ",option,addr,size);
            cache = load(cache, addr, size, s, E, b);
            if (vflag)
                printf("\n");
            break;
        case 'S':
            if (vflag)
                printf("%c %llx,%ld ",option,addr,size);
            cache = store(cache, addr, size, s, E, b);
            if (vflag)
                printf("\n");
            break;
        case 'M':
            if (vflag)
                printf("%c %llx,%ld ",option,addr,size);
            cache = load(cache, addr, size, s, E, b);
            cache = store(cache, addr, size, s, E, b);
            if (vflag)
                printf("\n");
            break;
        default:
            break;
        }
    }
    // printf("%ld %ld %ld ", hit_count, miss_count, eviction_count);
    printSummary(hit_count, miss_count, eviction_count);
    fclose(fp);
    return 0;
}