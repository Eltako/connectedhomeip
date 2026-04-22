#include "memory.h"
#include <cstdlib>
#include <cstring>

namespace chip::util::memory {

namespace {
    AllocateForeverFunction g_allocateForeverFunction = nullptr;
}

void set_allocate_forever_function(AllocateForeverFunction func) {
    g_allocateForeverFunction = func;
}

void * default_allocate_forever(std::size_t size, std::size_t alignment) {
    return ::malloc(size);
}

void * allocate_forever(std::size_t size, std::size_t alignment) {
    void * result = nullptr;
    if (g_allocateForeverFunction == nullptr)
    {
        result = default_allocate_forever(size, alignment);
    }
    else
    {
        result = g_allocateForeverFunction(size, alignment);
    }
    if (result) {
        ::memset(result, 0, size);
    }
    return result;
}

} // namespace chip::util::memory
