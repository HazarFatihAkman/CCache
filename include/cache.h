#ifndef CCACHE_CACHE_H
#define CCACHE_CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* str;
typedef const char* c_str;

typedef struct {
    int index;
    void* value;
} Cache;

typedef struct {
    int size;
    str c_namespace;
    Cache** Caches;
} Cache_List;

extern int c_lists_size;
extern Cache_List** c_lists;

Cache_List* fetch_caches(c_str c_namespace);
void push_cache(c_str c_namespace, Cache* c);
void delete_cache(c_str c_namespace, Cache* c);

#endif