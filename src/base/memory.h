#ifndef BASE_MEMORY_H
#define BASE_MEMORY_H

#include "base.h"

#define ARENA_DEFAULT_SIZE KiloBytes(64)

typedef struct {
    void* mem;
    u64 pos;
} Arena;

#define arena_init() arena_init_sized(ARENA_DEFAULT_SIZE)
Arena* arena_init_sized(u64 size);

// allocate memory in arena
void* arena_alloc(Arena* a, u64 size);

// free entire arena
void arena_free(Arena* a);

#endif // !BASE_MEMORY_H
