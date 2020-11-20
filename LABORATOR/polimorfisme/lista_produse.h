#include "produs_perisabil.h"
#include "produs_neperisabil.h"

#ifndef LISTA_H
#define LISTA_H

class ListaProduse
{
    Produs **produse;
    size_t i;

    void alocare(size_t dim);
    // void realocare(size_t dim_noua);

public:
    ListaProduse();
    ListaProduse(const ListaProduse &);
    ListaProduse(size_t dimensiune);

    void adauga_produs_perisabil(ProdusPerisabil &p);
    void adauga_produs_neperisabil(ProdusNeperisabil &p);

    void sterge_produs(size_t index);

    Produs &operator[](size_t i);
    friend ostream &operator<<(ostream &out, ListaProduse &l);
};

#endif