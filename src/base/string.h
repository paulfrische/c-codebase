#ifndef STRING
#define STRING

#include <stdbool.h>

/*
Convention:
functions operating on Strings should be named after the following scheme:
str_<short name for action>
*/

#include "base.h"
#include "memory.h"

typedef struct {
    char *str;
    u64 len;
} String;

// allocate string in arena
String str_alloc(Arena *arena, u64 len);

// generate string from literal
String str_literal(Arena *arena, const char *s);

// coppy string into new one
String str_copy(Arena *arena, String s);

// compare two strings
bool str_eq(String a, String b);

// test if a is contained in b
bool str_in(Arena *arena, String a, String b);

// concat two strings in arena
String str_cat(Arena *arena, String a, String b);

#endif // !STRING
