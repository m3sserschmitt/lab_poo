#include "masina_undercover.h"

MasinaUndercover::MasinaUndercover(): Automobil()
{
    this->viteza = 0;
    this->nr_gloante = 0;
}

MasinaUndercover::MasinaUndercover(string nume, string model, string utilizare, int viteza, int nr_gloante): Automobil(nume, model, utilizare)
{
    this->viteza = viteza;
    this->nr_gloante = nr_gloante;
}


void MasinaUndercover::afisare()
{
    Automobil::afisare();
    cout << ", viteza_maxima: " << this->viteza << ", nr_gloante: " << this->nr_gloante;
}
