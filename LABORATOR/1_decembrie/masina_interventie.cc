#include "masina_interventie.h"

MasinaInterventie::MasinaInterventie(): Automobil()
{
    this->nr_locuri = 0;
    this->mitraliera = false;
}

MasinaInterventie::MasinaInterventie(string marca, string model, string utilizare, int locuri, bool mitraliera): Automobil(marca, model, utilizare)
{
    this->nr_locuri = locuri;
    this->mitraliera = mitraliera;
}

void MasinaInterventie::afisare()
{
    Automobil::afisare();
    cout << " locuri: " << this->nr_locuri << " mitraliera: " << this->mitraliera; 
}
