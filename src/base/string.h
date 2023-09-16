#ifndef STRING
#define STRING

#include "base.h"
#include "memory.h"

typedef struct {
    char *str;
    u64 len;
} String;

String alloc_string(Arena *a, u64 len);

#endif // !STRING
