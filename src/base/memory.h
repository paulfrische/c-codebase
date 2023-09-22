#ifndef BASE_MEMORY_H
#define BASE_MEMORY_H

#include "base.h"

//////////////////////
// Custom Allocator //
//////////////////////

void* c_alloc(u64 size);
void c_free(void* memory, u64 size);

////////////
// ARENAS //
////////////

typedef struct {
    u64 id;
    void* mem;
    u64 size;
    u64 pos;
} Arena;

static u64 arena_count = 0;

#define ARENA_DEFAULT_SIZE KiloBytes(64)
#define ArenaInit() arena_init_sized(ARENA_DEFAULT_SIZE)
Arena* arena_init_sized(u64 size);

// allocate memory in arena
void* arena_alloc(Arena* a, u64 size);

// free entire arena
void arena_free(Arena* a);

#endif // !BASE_MEMORY_H
