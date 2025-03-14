#ifndef CACHE_H
#define CACHE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Cache_List *fetch_caches(char *c_namespace);
void push_cache(char *c_namespace, Cache *c);
void delete_cache(char *c_namespace, Cache *c);

#endif