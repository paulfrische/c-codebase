#include "string.h"
#include "base.h"
#include "memory.h"
#include <string.h>

// allocate string in arena
String str_alloc(Arena *arena, u64 len) {
    char *str = (char *)alloc_arena(arena, len);

    String s;
    s.str = str;
    s.len = len;

    return s;
}

// generate string from literal (with \0)
String str_literal(Arena *arena, const char *s) {
    // add one for \0
    u64 len = strlen(s) + 1;
    char *str = (char *)alloc_arena(arena, len);

    String string;
    strcpy(str, s);
    string.str = str;
    string.len = len;

    return string;
}

// coppy string into new one
String str_copy(Arena *arena, String s) {
    char* str = (char*)alloc_arena(arena, s.len);
    strcpy(str, s.str);
    String s2;
    s2.str = str;
    s2.len = s.len;

    return s2;
}

// compare two strings
bool str_eq(Arena *arena, String a, String b) {}

// test if a is contained in b
bool str_in(Arena *arena, String a, String b) {}

// concat two strings in arena
String str_cat(Arena *arena, String a, String b) {}
