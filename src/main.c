#include "base/base.h"
#include "base/memory.h"
#include "base/string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    Assert(Min(1, 2) == 1);
    Assert(Max(1, 2) == 2);

    Arena *arena = make_arena();
    String s = str_literal(arena, "Hello World");
    Assert(s.len == 12);

    String s2 = str_copy(arena, s);
    Assert(s.str != s2.str);

    // test str_eq
    String s3 = str_literal(arena, "This string is different from the others");
    Assert(str_eq(s, s2));
    Assert(!str_eq(s, s3));

    // test starts with
    Assert(str_starts_with(s3, str_literal(arena, "This")));

    // test str_contains
    Assert(str_contains(str_literal(arena, "is"), s3));

    // test str_cat
    Assert(str_eq(str_literal(arena, "Hello World"),
                  str_cat(arena, str_literal(arena, "Hello "),
                          str_literal(arena, "World"))));

    arena_free(arena);
    return EXIT_SUCCESS;
}
