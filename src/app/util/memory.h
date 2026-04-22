#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <memory>

namespace chip::util::memory {

using AllocateForeverFunction = void * (*)(std::size_t size, std::size_t alignment);

/**
 * @brief Sets the function to be used for allocate_forever. This allows the application to provide its own implementation of allocate_forever.
 *        The function should return a pointer to a block of memory that is at least size bytes in size and is aligned to alignment bytes.
 *        The memory returned by this function will not be freed until the device is reset, so it should be used for memory that is expected to be used for the entire lifetime of the device.
 *        Note that some memory is allocate before your main() function is called.
 *        If you need these allocation to reside in specific memory region, then you should provide your own implementation of default_allocate_forever.
 */
void set_allocate_forever_function(AllocateForeverFunction func);

/*
* @brief Default implementation of allocate_forever. This function is weakly linked, so it can be overridden by the application.
*        The default implementation uses aligned_alloc, which may not be suitable for all platforms. The application can provide
*        its own implementation by defining a function with the same signature and marking it as weak.
*/
void * default_allocate_forever(std::size_t size, std::size_t alignment) __attribute__((weak));

/**
 * @brief Allocates memory that is expected to be used for the entire lifetime of the device.
 *        This memory will not be freed until the device is reset.
 */
void * allocate_forever(std::size_t size, std::size_t alignment);

template <typename T>
T * allocate_forever(std::size_t count = 1)
{
    if (count == 0)
    {
        return nullptr;
    }

    if (count > (std::numeric_limits<std::size_t>::max() / sizeof(T)))
    {
        return nullptr;
    }

    T * result = static_cast<T *>(allocate_forever(sizeof(T) * count, alignof(T)));
    if (result == nullptr)
    {
        return nullptr;
    }

    std::uninitialized_default_construct_n(result, count);
    return result;
}

}
