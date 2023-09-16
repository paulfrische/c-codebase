#include "string.h"
#include "base.h"
#include "memory.h"
#include <stdio.h>
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
    char *str = (char *)alloc_arena(arena, s.len);
    strcpy(str, s.str);
    String s2;
    s2.str = str;
    s2.len = s.len;

    return s2;
}

// compare two strings
bool str_eq(String a, String b) {
    if (a.len != b.len) {
        return false;
    }

    // cant use strcmp because custom strings don't have to have a \0
    for (u64 i = 0; i < a.len; i++) {
        if (a.str[i] != b.str[i]) {
            return false;
        }
    }

    return true;
}
// test if a starts with b
bool str_starts_with(String a, String b) {
    if (a.len < b.len) {
        return false;
    }

    for (u64 i = 0; i < b.len; i++) {
        // skip '\0' for ease of use
        if (b.str[i] == '\0') {
            continue;
        }

        if (a.str[i] != b.str[i]) {
            return false;
        }
    }

    return true;
}

// test if a is contained in b
bool str_contains(String a, String b) {
    if (a.len > b.len) {
        return false;
    }
    for (u64 i = 0; i < a.len; i++) {
        String s;
        s.str = b.str + i;
        s.len = b.len - i;

        if (str_starts_with(s, a)) {
            return true;
        }
    }

    return false;
}

// concat two strings in arena
String str_cat(Arena *arena, String a, String b) {}
