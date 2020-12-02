#include "automobil.h"

class ListaAutomobile
{
    Automobil **lista_automobile;
    size_t count;

public:
    ListaAutomobile();
    ListaAutomobile(const ListaAutomobile &l);

    size_t dimensiune();

    Automobil *operator[](size_t i);
    ListaAutomobile operator+(Automobil &a);

    ListaAutomobile &operator=(const ListaAutomobile &l);
};