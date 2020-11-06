#include <stdlib.h>
#include <string.h>
#include <exception>

#ifndef MEM_H
#define MEM_H

template <class T>
void allocate_memory(T **to, size_t size)
{
    *to = reinterpret_cast<T *>(malloc(size * sizeof(T)));
    memset(reinterpret_cast<void *>(*to), 0, size * sizeof(T));
}

template <typename T, typename... Args>
void memory_cleanup(T t)
{
    if (t)
    {
        // try
        // {
        free(t);
        // }
        // catch (const std::exception &e)
        // {
        // std::cerr << e.what() << '\n';
        // }
    }
}

template <typename T, typename... Args>
void memory_cleanup(T t, Args... args)
{
    if (t)
    {
        // try
        // {
        free(t);
        // }
        // catch (const std::exception &e)
        // {
        // std::cerr << e.what() << '\n';
        // }
    }

    memory_cleanup(args...);
}

template <typename... Args>
void free_memory(Args... args)
{
    try
    {
        memory_cleanup(args...);
    }
    catch (const char *)
    {
    }
}

#endif