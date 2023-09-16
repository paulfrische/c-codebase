#include "base/base.h"
#include "base/memory.h"
#include "base/string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[] = "Hello World";
    Assert(ArrayCount(str) == 12);
    Assert(Min(1, 2) == 1);
    Assert(Max(1, 2) == 2);

    Arena* a = make_arena();
    String s = alloc_string(a, 12);
    strcpy(s.str, "Hello World");

    printf("%s\n", s.str);

    free_arena(a);

    return EXIT_SUCCESS;
}
