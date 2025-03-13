#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if _WIN32
    #define CACHE_API __declspec(dllexport)
#else
    #define CACHE_API __attribute__((visibility("default")))
#endif

typedef struct {
    int index;
    void *value;
} Cache;

typedef struct {
    int size;
    char *c_namespace;
    Cache **Caches;
} Cache_List;

extern int c_lists_size;
extern Cache_List **c_lists;

CACHE_API Cache_List *fetch_caches(char *c_namespace);
CACHE_API void push_cache(char *c_namespace, Cache *c);
CACHE_API void delete_cache(char *c_namespace, Cache *c);

#endif