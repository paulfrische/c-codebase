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

    printf("%s\n", s.str);

    free_arena(arena);
    return EXIT_SUCCESS;
}
