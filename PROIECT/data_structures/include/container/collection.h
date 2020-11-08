#include "../iterable/iterable.h"

#include "../../../util/include/mem.h"

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

    void set_data(T *data, size_t size);
    void set_data(std::initializer_list<T> l);

    virtual void insert(T elem, size_t i);

public:
    Collection();
    Collection(size_t size);
    Collection(const Collection<T> &c);

    Collection(std::initializer_list<T> l);

    ~Collection();

    virtual Iterator<T> begin();
    virtual Iterator<T> end();

    void reserve(size_t);
    long resize(size_t);
    void clear();

    bool is_empty();
    size_t get_size();

    T get(size_t index);
    virtual ssize_t search(T);
    virtual void add(T);
    virtual void remove(size_t);

    template <class t>
    friend std::ostream &operator<<(std::ostream &, Collection<t>);

    template <class t>
    friend Collection<t> &operator<<(Collection<t> &, t);
};

template <class T>
Collection<T>::Collection()
{
    this->reserve(0);
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
    if (this != &c)
    {
        this->reserve(c.size);
        this->set_data(c.data, c.current_size);
    }
}

template <class T>
Collection<T>::Collection(std::initializer_list<T> l)
{
    this->reserve(l.size());
    this->set_data(l);
}

template <class T>
Collection<T>::~Collection()
{
    free_memory(this->data);
    this->data = NULL;
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
void Collection<T>::set_data(T *data, size_t size)
{
    copy_memory(this->data, data, size);
    this->current_size = size;
}

template <class T>
void Collection<T>::set_data(std::initializer_list<T> l)
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

    allocate_memory(&this->data, size);
}

template <class T>
long Collection<T>::resize(size_t size)
{
    T *old = this->data;

    this->data = realloc_memory(this->data, this->size, size);
    this->size = size;
    
    return this->data - old;
}

template <class T>
void Collection<T>::clear()
{
    free_memory(this->data);
    this->current_size = 0;
}

template <class T>
bool Collection<T>::is_empty()
{
    return not this->current_size;
}

template <class T>
size_t Collection<T>::get_size()
{
    return this->size;
}

template <class T>
T Collection<T>::get(size_t index)
{
    return this->data[index];
}

template <class T>
ssize_t Collection<T>::search(T elem)
{
    Iterator<T> it = this->begin();

    for (; not it.out_of_range(); it.next())
    {
        if (it.value() == elem)
        {
            return it.index();
        }
    }

    return -1;
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
void Collection<T>::remove(size_t i)
{
    this->memory_shift_left(this->data + i + 1);
    this->current_size--;
}

template <class T>
void Collection<T>::insert(T elem, size_t i)
{
    long delta = this->current_size + 1 - this->size;
    if (delta > 0)
    {
        this->resize(this->size + delta);
    }

    this->memory_shift_right(this->data + i);
    this->data[i] = elem;
    this->current_size++;
}

template <class T>
Iterator<T> Collection<T>::begin()
{
    return Iterator<T>(this->data, this->data + this->current_size, this->data);
}

template <class T>
Iterator<T> Collection<T>::end()
{
    return Iterator<T>(this->data, this->data + this->current_size, this->data + this->current_size);
}

template <class t>
std::ostream &operator<<(std::ostream &out, Collection<t> c)
{
    Iterator<t> it = c.begin();
    Iterator<t> it_end = c.end();

    out << "{";
    for (it_end.previous(); it < it_end; it.next())
    {
        out << it.value() << ", ";
    }

    if (not c.is_empty())
    {
        out << it_end.value();
    }

    out << "}";

    return out;
}

template <class t>
Collection<t> &operator<<(Collection<t> &c, t elem)
{
    c.add(elem);
    return c;
}

#endif