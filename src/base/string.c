#include "string.h"
#include "memory.h"

String alloc_string(Arena *a, u64 len) {
    char *str = (char *)alloc_arena(a, len);

    String s;
    s.str = str;
    s.len = len;

    return s;
}
