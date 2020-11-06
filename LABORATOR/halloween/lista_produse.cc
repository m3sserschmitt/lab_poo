#include "lista_produse.h"

ListaProduse::ListaProduse()
{
}

ListaProduse::ListaProduse(const ListaProduse &l)
{
    this->lista = l.lista;
}

Decoratiune &ListaProduse::operator[](size_t index)
{
    return this->lista[index - 1];
}

float ListaProduse::pret()
{
    float total = 0;
    for (size_t i = 0; i < this->lista.size(); i++)
    {
        total += this->lista[i].pret();
    }

    return total;
}

void ListaProduse::remove(size_t index)
{
    std::vector<Decoratiune>::iterator it = this->lista.begin() + index - 1;
    this->lista.erase(it);
}

size_t ListaProduse::numar_produse()
{
    return this->lista.size();
}

ListaProduse operator+(ListaProduse l, Decoratiune d)
{
    l.lista.push_back(d);
    return l;
}

std::ostream &operator<<(std::ostream &out, ListaProduse &l)
{
    size_t i = 1;
    for (; i <= l.numar_produse() - 1; i++)
    {
        out << l[i] << "\n";
    }

    if (l.numar_produse())
    {
        out << l[i];
    }

    return out;
}