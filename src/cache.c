#include "../include/cache.h"

int c_lists_size = 0;
Cache_List **c_lists = NULL;

static Cache_List *find_c_list(char *c_namespace) {
    for (int i = 0; i < c_lists_size; i++) {
        if (c_lists[i]->c_namespace == c_namespace) {
            return c_lists[i];
        }
    }

    return NULL;
}

CACHE_API Cache_List *fetch_caches(char *c_namespace) {
    return find_c_list(c_namespace);
}

CACHE_API void push_cache(char *c_namespace, Cache *c) {
    Cache_List *c_list = find_c_list(c_namespace);
    int c_list_null = c_list == NULL;
    if (c_list_null) {
        c_list = (Cache_List*)malloc(sizeof(Cache_List));
        c_list->size = 0;
        c_list->c_namespace = c_namespace;
        c_list->Caches = (Cache**)malloc(sizeof(Cache));
    }
    else {
        c_list->Caches = (Cache**)realloc(c_list->Caches, (c_list->size + 1) * sizeof(Cache));
    }
    c->index = c_list->size;
    c_list->Caches[c_list->size] = c;
    c_list->size++;
    c_lists[c_lists_size] = c_list;

    if (c_list_null) {
        c_lists_size++;
        c_lists = (Cache_List**)realloc(c_lists, c_lists_size * sizeof(Cache_List));
    }
}

CACHE_API void delete_cache(char *c_namespace, Cache *c) {
    Cache_List *c_list = find_c_list(c_namespace);

    for (int i = 0; i < c_list->size; i++) {
        if (i >= c->index && i <  c_list->size - 1) {
            c_list->Caches[i] = c_list->Caches[i+1];
            c_list->Caches[i]->index = i;
        }

        if (i == ( c_list->size - 1)) {
            c_list->Caches[i] = NULL;
        }
    }

    c_list->size--;
    c_list->Caches = realloc(c_list->Caches, c_list->size * sizeof(Cache));
    free(c);
}