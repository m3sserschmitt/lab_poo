#include "masina_receptie.h"

MasinaReceptie::MasinaReceptie(): Automobil()
{
    this->distanta_acustica = 0;
    this->distanta_video = 0;
}

MasinaReceptie::MasinaReceptie(string marca, string model, string utilizare, int distanta_acustica, int distanta_video): Automobil(marca, model, utilizare)
{
    this->distanta_acustica = distanta_acustica;
    this->distanta_video = distanta_video;
}


void MasinaReceptie::afisare()
{
    Automobil::afisare();
    cout << ", distanta_acustica: " << this->distanta_acustica << ", distanta_video: " << this->distanta_video;
}
