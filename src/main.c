#include "base/base.h"
#include "base/filesystem.h"
#include "base/memory.h"
#include "base/string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    LOG("%s", "Hello World");
    Assert(Min(1, 2) == 1);
    Assert(Max(1, 2) == 2);

    Arena* arena = arena_init();
    String s = str_from_c_str(arena, "Hello World");
    Assert(s.len == 12);

    String s2 = str_copy(arena, s);
    Assert(s.str != s2.str);

    // test str_eq
    String s3 = str_from_c_str(arena, "This string is different from the others");
    Assert(str_eq(s, s2));
    Assert(!str_eq(s, s3));

    // test starts with
    Assert(str_starts_with(s3, str_from_c_str(arena, "This")));

    // test str_find
    Assert(str_find(s3, str_from_c_str(arena, " is")) == 11);

    // test str_contains
    Assert(str_contains(s3, str_from_c_str(arena, "is")));

    // test str_cat
    Assert(str_eq(str_from_c_str(arena, "Hello World"),
        str_cat(arena, str_from_c_str(arena, "Hello "),
            str_from_c_str(arena, "World"))));

    // test str_default_c_str
    String s4 = str_from_c_str(arena, "Chello");
    s4.len -= 1; // "remove" the null terminator
    char* s5 = str_to_c_str(arena, s4);
    printf("%s\n", s5);

    // test filesystem_read_file
    String s6 = filesystem_read_file(arena, str_from_c_str(arena, "./src/main.c"));
    printf("%s\n", str_to_c_str(arena, s6));

    // test filesystem_write_file
    filesystem_write_file(str_from_c_str(arena, "tmp.txt"), str_from_c_str(arena, "Hello World!"));

    // test filesystem_append_file
    filesystem_append_file(str_from_c_str(arena, "tmp.txt"), str_from_c_str(arena, "\nSome more text"));

    arena_free(arena);
    return EXIT_SUCCESS;
}
