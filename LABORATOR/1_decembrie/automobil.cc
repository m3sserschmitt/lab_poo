#include "automobil.h"

Automobil::Automobil()
{
    this->marca = "Necunoscut";
    this->model = "Necunoscut";
    this->utilizare = "Necunoscut";
}

Automobil::Automobil(string marca, string model, string utilizare)
{
    this->marca = marca;
    this->model = model;
    this->utilizare = utilizare;
}

void Automobil::afisare()
{
    cout << marca << " " << model << ", utilizare: " << utilizare;
}
