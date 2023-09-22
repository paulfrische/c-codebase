#include "memory.h"
#include "base.h"
#include "logging.h"
#include <stdlib.h>
#include <sys/mman.h>

//////////////////////
// Custom Allocator //
//////////////////////

void* c_alloc(u64 size) { return mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0); }
void c_free(void* memory, u64 size) { munmap(memory, size); }

////////////
// ARENAS //
////////////

Arena* arena_init_sized(u64 size)
{
    Arena* a = (Arena*)c_alloc(sizeof(Arena));
    a->id = arena_count;
    a->mem = c_alloc(size);
    a->size = size;
    a->pos = 0;

    arena_count++;

    DEBUG("init arena [%lu] at %p", a->id, a);

    return a;
}

void* arena_alloc(Arena* a, u64 size)
{
    void* memory = a->mem + a->pos;
    a->pos += size;
    DEBUG("allocation in arena [%lu]. Using %lu bytes", a->id, a->pos);
    return memory;
}

void arena_free(Arena* a)
{
    DEBUG("free arena [%lu] at %p", a->id, a);
    c_free(a->mem, a->size);
    c_free(a, sizeof(Arena));
}
