#include "memory.h"
#include "base.h"
#include <stdlib.h>

// create arenas on the heap
Arena *make_arena() { return make_arena_sized(ARENA_DEFAULT_SIZE); }
Arena *make_arena_sized(u64 size) {
    Arena *a = (Arena *)malloc(sizeof(Arena));
    a->mem = malloc(size);
    a->pos = 0;
    return a;
}

// allocate memory in arena
void *arena_alloc(Arena *a, u64 size) {
    void *memory = a->mem + a->pos;
    a->pos += size;
    LOG("allocation in arena. Using %lu bytes\n", a->pos);
    return memory;
}

// free entire arena
void arena_free(Arena *a) {
    LOG("free arena at %p", a);
    free(a->mem);
    free(a);
}
