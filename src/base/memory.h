#ifndef MEMORY
#define MEMORY

#include "base.h"

#define ARENA_DEFAULT_SIZE KiloBytes(64)

typedef struct {
    void *mem;
    u64 pos;
} Arena;

Arena *make_arena();
Arena *make_arena_sized(u64 size);

// allocate memory in arena
void *arena_alloc(Arena *a, u64 size);

// free entire arena
void arena_free(Arena *a);

#endif // MEMORY
