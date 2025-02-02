#include "iterable.h"

#include "../../util/include/mem.h"

#include <cstddef>
#include <iostream>

using namespace std;

#ifndef COLLECTION_H
#define COLLECTION_H

template <class T>
class Collection : public Iterable<T>
{
protected:
    T *data;
    size_t size;
    size_t current_size;

    void memory_shift_left(T *addr);
    void memory_shift_right(T *addr);

    void set_data(const T *data, size_t size);
    void set_data(const std::initializer_list<T> &l);

public:
    Collection();
    Collection(size_t size);
    Collection(const Collection<T> &c);
    Collection(const std::initializer_list<T> &l);

    virtual ~Collection() = 0;

    void reserve(size_t size);
    long resize(size_t new_size);

    size_t get_size() const;
    bool is_empty() const;

    Iterator<T> begin() const;
    Iterator<T> end() const;

    virtual void add(T elem);
    virtual ssize_t search(T) const = 0;

    void clear();
};

template <class T>
Collection<T>::Collection()
{
    this->reserve(1);
    this->current_size = 0;
}

template <class T>
Collection<T>::Collection(size_t size)
{
    this->reserve(size);
    this->current_size = 0;
}

template <class T>
Collection<T>::Collection(const Collection<T> &c)
{
    this->reserve(c.size);
    this->set_data(c.data, c.current_size);
}

template <class T>
Collection<T>::Collection(const std::initializer_list<T> &l)
{
    this->reserve(l.size());
    this->set_data(l);
}

template <class T>
Collection<T>::~Collection()
{
    delete[] this->data;
    // free_memory(this->data);
}

template <class T>
void Collection<T>::memory_shift_left(T *addr)
{
    if (addr <= this->data or addr >= this->data + this->current_size)
    {
        return;
    }

    size_t block_length = this->current_size - (addr - this->data);
    copy_memory(addr - 1, addr, block_length);
}

template <class T>
void Collection<T>::memory_shift_right(T *addr)
{
    if (addr < this->data or addr >= this->data + this->current_size)
    {
        return;
    }

    long delta = this->current_size + 1 - this->size;

    long reloc_delta = 0;
    if (delta > 0)
    {
        reloc_delta = this->resize(this->size + delta);
    }

    addr += reloc_delta;
    size_t block_length = this->current_size - (addr - this->data);

    copy_memory(addr + 1, addr, block_length);
}

template <class T>
void Collection<T>::set_data(const T *data, size_t size)
{
    copy_memory(this->data, data, size);
    this->current_size = size;
}

template <class T>
void Collection<T>::set_data(const std::initializer_list<T> &l)
{
    typename std::initializer_list<T>::const_iterator it = l.begin();
    typename std::initializer_list<T>::const_iterator it_end = l.end();

    this->current_size = 0;
    for (; it != it_end; it++)
    {
        this->data[this->current_size++] = *it;
    }
}

template <class T>
void Collection<T>::reserve(size_t size)
{
    this->size = size;
    this->current_size = 0;

    this->data = new T[size];
    // allocate_memory(&this->data, size);
}

template <class T>
long Collection<T>::resize(size_t size)
{
    if (this->data != NULL)
    {
        T *old = this->data;

        this->data = realloc_memory(this->data, this->size, size);
        this->size = size;

        return this->data - old;
    }
    
    this->reserve(size);
    return 0;
}

template <class T>
size_t Collection<T>::get_size() const
{
    return this->current_size;
}

template <class T>
bool Collection<T>::is_empty() const
{
    return not this->current_size;
}

template <class T>
Iterator<T> Collection<T>::begin() const
{
    return Iterator<T>(this->data, this->data + this->current_size, this->data);
}

template <class T>
Iterator<T> Collection<T>::end() const
{
    return Iterator<T>(this->data, this->data + this->current_size, this->data + this->current_size);
}

template <class T>
void Collection<T>::add(T elem)
{
    long delta = this->current_size + 1 - this->size;
    if (delta > 0)
    {
        this->resize(this->size + delta);
    }

    this->data[this->current_size] = elem;
    this->current_size++;
}

template <class T>
void Collection<T>::clear()
{
    delete[] this->data;
    // free_memory(this->data);
    this->current_size = 0;
    this->data = NULL;
}

#endif