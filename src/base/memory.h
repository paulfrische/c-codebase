#ifndef BASE_MEMORY_H
#define BASE_MEMORY_H

#include "base.h"

#define ARENA_DEFAULT_SIZE KiloBytes(64)

typedef struct {
    void *mem;
    u64 pos;
} Arena;

Arena *make_arena();
Arena *make_arena_sized(u64 size);

// allocate BASE_MEMORY_H in arena
void *arena_alloc(Arena *a, u64 size);

// free entire arena
void arena_free(Arena *a);

#endif // !BASE_MEMORY_H
