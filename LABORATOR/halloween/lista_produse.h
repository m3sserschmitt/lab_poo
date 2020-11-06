#ifndef LISTA_PRODUSE_H
#define LISTA_PRODUSE_H

#include "decoratiune.h"

#include <iostream>
#include <vector>

class ListaProduse
{
    std::vector<Decoratiune> lista;

public:
    ListaProduse();
    ListaProduse(const ListaProduse &l);

    float pret();
    void remove(size_t index);
    size_t numar_produse();

    Decoratiune &operator[](size_t index);
    
    friend ListaProduse operator+(ListaProduse, Decoratiune);
    friend std::ostream &operator<<(std::ostream &, ListaProduse &);
};

#endif