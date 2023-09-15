/* this is written by 林童奕凡 10225501422 */

// #include "cachelab.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

#define ADDR_BITS 64
#define type_l unsigned long
// #define type_l_scan "%lx"

long hit_count = 0, miss_count = 0, eviction_count = 0;

typedef struct cache_line_define
{
    int valid;
    type_l tag;
    int *block;
    int LRU;
} type_cache_line;

typedef struct set_define
{
    type_cache_line *line;
} type_set;

typedef struct cache_define
{
    type_set *sets;
} type_cache;

type_cache init_cache(type_cache cache, int s, int E, int b)
{
    cache.sets = (type_set *)malloc(sizeof(type_set) * (1 << s));
    for (int i = 0; i < (1 << s); i++)
    {
        cache.sets[i].line = (type_cache_line *)malloc(sizeof(type_cache_line) * E);
        for (int j = 0; j < E; j++)
        {
            cache.sets[i].line[j].valid = 0;
            cache.sets[i].line[j].tag = 0;
            cache.sets[i].line[j].block = (int *)malloc(sizeof(int) * (1 << b));
            cache.sets[i].line[j].LRU = 0;
        }
    }
    return cache;
}

int B2D(int bin_num)
{
    int dec_num = 0;
    int base = 1;
    while (bin_num > 0)
    {
        dec_num += (bin_num % 10) * base;
        bin_num /= 10;
        base *= 2;
    }
    return dec_num;
}

int get_set(type_l addr, int s, int b)
{
    return B2D((addr >> b) & ((1 << s) - 1));
}

type_l get_tag(type_l addr, int s, int b)
{
    return addr >> (s + b);
}

int get_block(type_l addr, int s, int b)
{
    return B2D(addr & ((1 << b) - 1));
}

type_cache load(type_cache cache, type_l addr, int size, int s, int E, int b)
{
    int set_index = get_set(addr, s, b);
    type_l tag = get_tag(addr, s, b);
    // int block_index = get_block(addr, s, b);
    for (int i = 0; i < E; i++)
    {
        if (cache.sets[set_index].line[i].valid == 1 && cache.sets[set_index].line[i].tag == tag)
        {
            hit_count++;
            cache.sets[set_index].line[i].LRU = 0;
            for (int j = 0; j < E; j++)
            {
                if (j != i)
                {
                    cache.sets[set_index].line[j].LRU++;
                }
            }
            return cache;
        }
    }
    // 未命中的情形
    miss_count++;
    for (int i = 0; i < E; i++)
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
            return cache;
        }
    }
    // 需要驱逐的情形
    eviction_count++;
    int max_LRU = 0;
    int max_index = 0;
    for (int i = 0; i < E; i++)
    {
        if (cache.sets[set_index].line[i].LRU > max_LRU)
        {
            max_LRU = cache.sets[set_index].line[i].LRU;
            max_index = i;
        }
    }
    cache.sets[set_index].line[max_index].tag = tag;
    cache.sets[set_index].line[max_index].LRU = 0;
    for (int j = 0; j < E; j++)
    {
        if (j != max_index)
        {
            cache.sets[set_index].line[j].LRU++;
        }
    }
    return cache;
}

type_cache store(type_cache cache, type_l addr, int size, int s, int E, int b)
{
    int set_index = get_set(addr, s, b);
    type_l tag = get_tag(addr, s, b);
    // int block_index = get_block(addr, s, b);
    int max_LRU = -1;
    int max_index = -1;
    for (int i = 0; i < E; i++)
    {
        if (cache.sets[set_index].line[i].valid == 0 && cache.sets[set_index].line[i].LRU > max_LRU)
        {
            max_LRU = cache.sets[set_index].line[i].LRU;
            max_index = i;
        }
    }
    if (max_index != -1)
    {
        hit_count++;
        cache.sets[set_index].line[max_index].valid = 1;
        cache.sets[set_index].line[max_index].tag = tag;
        cache.sets[set_index].line[max_index].LRU = 0;
        for (int j = 0; j < E; j++)
        {
            if (j != max_index)
            {
                cache.sets[set_index].line[j].LRU++;
            }
        }
        return cache;
    }
    // 未命中的情形
    miss_count++;
    max_index = 0;
    max_LRU = 0;
    for (int i = 0; i < E; i++)
    {
        if (cache.sets[set_index].line[i].LRU > max_LRU)
        {
            max_LRU = cache.sets[set_index].line[i].LRU;
            max_index = i;
        }
    }
    cache.sets[set_index].line[max_index].tag = tag;
    cache.sets[set_index].line[max_index].LRU = 0;
    for (int j = 0; j < E; j++)
    {
        if (j != max_index)
        {
            cache.sets[set_index].line[j].LRU++;
        }
    }
    return cache;
}

int main(int argc, char *argv[])
{
    int opt, s = 0, E = 0, b = 0;
    s = 4; E = 1; b = 4;
    // int m = ADDR_BITS;
    // FILE *fp = NULL;
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
            // fp = fopen(optarg, "r");
            break;
        default:
            break;
        }
    }
    type_cache cache;
    cache = init_cache(cache, s, E, b);
    char option, cflag;
    type_l addr;
    int size;
    while (/*f*/ scanf(/*fp, */ "%c%c%lx,%d", &cflag, &option, &addr, &size) != EOF)
    {
        fflush(stdin);
        //printf("%c %c %lx %d\n", cflag, option, addr, size);
        if (cflag == 'I')
            continue;
        switch (option)
        {
        case 'L':
            cache = load(cache, addr, size, s, E, b);
            break;
        case 'S':
            cache = store(cache, addr, size, s, E, b);
            break;
        case 'M':
            cache = load(cache, addr, size, s, E, b);
            cache = store(cache, addr, size, s, E, b);
            break;
        default:
            break;
        }
    }
    printf("%ld %ld %ld ", hit_count, miss_count, eviction_count);
    // printSummary(hit_count, miss_count, eviction_count);
    // fclose(fp);
    return 0;
}