# CCache

> It's for easy caching data. There's Cache_List to list caches by c_namespace and inside Caches for storage the datas. You can check usage in "test/main.c". 


# Example
``` c
  typedef struct {
    int id;
    char *name;
  } Test;

  Test *t = (Test*)malloc(sizeof(Test));
  t->name = "Test";
  t->id = 1;

  Cache *struct_cache = (Cache*)malloc(sizeof(Cache));
  struct_cache->index = 0;
  struct_cache->value = t;

  Test *t_2 = (Test*)struct_cache->value;
  printf("%d | %s\n", t_2->id, t_2->name);
```

## Test Output

![Screenshot 2025-03-13 083559](https://github.com/user-attachments/assets/a93b4d71-b826-4992-b0c7-61122365c14d)
