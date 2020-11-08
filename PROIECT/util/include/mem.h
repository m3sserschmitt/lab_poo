#include <stdlib.h>
#include <string.h>
#include <exception>

#ifndef MEM_H
#define MEM_H
/*
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
*/

template <class T>
void allocate_memory(T **dest, size_t size)
{
    // allocate new buffer of type T of size 'size';
    *dest = new T[size];
}

template <class T>
void free_memory(T *buff)
{
    // delete allocated buffer;
    delete[] buff;
}

template <class T>
void copy_memory(T *dest, T *from, size_t size)
{
    T *temp;
    // allocate memory for temporary buffer;
    allocate_memory(&temp, size);

    // copy data to temp buffer;
    size_t i = 0;
    for(; i < size; i ++)
    {
        temp[i] = from[i];
    }

    // copy data from temp buffer to destination;
    for(i = 0; i < size; i ++)
    {
        dest[i] = temp[i];
    }
    
    // free temp buffer;
    free_memory(temp);
}

template <class T>
T *realloc_memory(T *buff, size_t old_size, size_t new_size)
{
    T *new_buffer;

    // allocate memory for new_buffer;
    allocate_memory(&new_buffer, new_size);

    // copy data from old buffer to new buffer;
    copy_memory(new_buffer, buff, old_size);

    // free old buffer;
    free_memory(buff);

    // return newly allocated buffer;
    return new_buffer;
}

#endif