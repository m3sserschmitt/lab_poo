#include "lista_automobile.h"

ListaAutomobile::ListaAutomobile()
{
    this->lista_automobile = new Automobil *[100];
    this->count = 0;
}

ListaAutomobile::ListaAutomobile(const ListaAutomobile &l)
{
    this->lista_automobile = new Automobil *[100];

    for (size_t i = 0; i < l.count; i++)
    {
        this->lista_automobile[i] = l.lista_automobile[i];
    }

    this->count = l.count;
}

size_t ListaAutomobile::dimensiune()
{
    return this->count;
}

Automobil *ListaAutomobile::operator[](size_t i)
{
    return this->lista_automobile[i];
}

ListaAutomobile ListaAutomobile::operator+(Automobil &a)
{
    ListaAutomobile lista_noua = *this;
    
    lista_noua.lista_automobile[this->count] = &a;
    lista_noua.count ++;

    return lista_noua;
}

ListaAutomobile &ListaAutomobile::operator=(const ListaAutomobile &l)
{
    if (this != &l)
    {
        for (int i = 0; i < 100; i++)
        {
            this->lista_automobile[i] = l.lista_automobile[i];
        }

        this->count = l.count;
    }

    return *this;
}