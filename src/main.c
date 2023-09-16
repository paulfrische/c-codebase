#include "base/base.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char str[] = "Hello World";
    Assert(ArrayCount(str) == 12);
    Assert(Min(1, 2) == 1);
    Assert(Max(1, 2) == 2);

    printf("Hello World!\n");

    return EXIT_SUCCESS;
}
