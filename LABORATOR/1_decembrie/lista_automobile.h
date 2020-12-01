#include "automobil.h"

class ListaAutomobile
{
    Automobil **lista_automobile;
    size_t count;

public:
    ListaAutomobile();

    Automobil *operator[](size_t i);
    ListaAutomobile operator+(Automobil &a);
};