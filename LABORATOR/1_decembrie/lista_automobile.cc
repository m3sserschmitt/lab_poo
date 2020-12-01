#include "lista_automobile.h"

ListaAutomobile::ListaAutomobile()
{
    this->lista_automobile = new Automobil *[100];
    this->count = 0;
}

Automobil *ListaAutomobile::operator[](size_t i)
{
    return this->lista_automobile[i];
}

ListaAutomobile ListaAutomobile::operator+(Automobil &a)
{
    ListaAutomobile lista_noua;
    lista_noua = *this;
    lista_noua.lista_automobile[this->count] = &a;

    return lista_noua;
}