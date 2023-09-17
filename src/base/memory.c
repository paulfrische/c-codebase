#include "memory.h"
#include "base.h"
#include <stdlib.h>

// create arenas on the heap
Arena* arena_init_sized(u64 size)
{
    Arena* a = (Arena*)malloc(sizeof(Arena));
    a->id = arena_count;
    a->mem = malloc(size);
    a->pos = 0;

    arena_count++;

    LOG("init arena %lu at %p", a->id, a);

    return a;
}

// allocate memory in arena
void* arena_alloc(Arena* a, u64 size)
{
    void* memory = a->mem + a->pos;
    a->pos += size;
    LOG("allocation in arena %lu. Using %lu bytes", a->id, a->pos);
    return memory;
}

// free entire arena
void arena_free(Arena* a)
{
    LOG("free arena %lu at %p", a->id, a);
    free(a->mem);
    free(a);
}
