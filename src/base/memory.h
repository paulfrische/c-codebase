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
void *alloc_arena(Arena *a, u64 size);

// free entire arena
void free_arena(Arena *a);

#endif // MEMORY
