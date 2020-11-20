#include "lista_produse.h"

ListaProduse::ListaProduse()
{
    this->alocare(100);
    this->i = 0;
}

ListaProduse::ListaProduse(const ListaProduse &p)
{
    this->alocare(p.i);
    
    for(size_t k = 0; k < p.i; k ++)
    {
        this->produse[k] = new Produs;
        this->produse[k] = p.produse[k];
    }

    this->i = p.i;
}

ListaProduse::ListaProduse(size_t dimensiune)
{
    this->alocare(dimensiune);
    this->i = 0;
}

void ListaProduse::alocare(size_t dim)
{
    this->produse = new Produs *[dim];
}
/*
void ListaProduse::realocare(size_t dim_noua)
{
    Produs **temp = new Produs *[this->i];

    for (size_t k = 0; k < this->i; k++)
    {
        temp[k] = this->produse[k];
    }

    delete[] this->produse;

    this->alocare(dim_noua);

    for (size_t k = 0; k < dim_noua; k++)
    {
        this->produse[k] = new Produs;
        this->produse[k] = temp[k];
    }

    delete[] temp;
}
*/
void ListaProduse::adauga_produs_neperisabil(ProdusNeperisabil &p)
{
    this->produse[this->i] = new ProdusNeperisabil;
    this->produse[this->i] = &p;

    this->i++;
}

void ListaProduse::adauga_produs_perisabil(ProdusPerisabil &p)
{
    this->produse[this->i] = new ProdusPerisabil;
    this->produse[this->i] = &p;

    this->i++;
}

void ListaProduse::sterge_produs(size_t index)
{
    this->produse[this->i] = NULL;

    for (int k = index; k < (int)this->i - 1; k++)
    {
        this->produse[k] = this->produse[k + 1];
    }

    if (this->i)
    {
        this->i--;
    }
}

Produs &ListaProduse::operator[](size_t i)
{
    return *(this->produse)[i];
}

ostream &operator<<(ostream &out, ListaProduse &l)
{
    for (int k = 0; k < (int)l.i - 1; k++)
    {
        out << *l.produse[k] << "\n";
    }

    if (l.i)
    {
        out << *l.produse[l.i - 1];
    }

    return out;
}
