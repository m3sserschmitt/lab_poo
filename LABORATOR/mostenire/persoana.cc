#include "personana.h"

Persoana::Persoana()
{
    this->nume = "anonim";
    this->cnp = "0000000000";
    this->inaltime = 0;
}

Persoana::Persoana(const Persoana &p)
{
    this->nume = p.nume;
    this->cnp = p.cnp;
    this->inaltime = p.inaltime;
}

Persoana::Persoana(string nume, string cnp, float inaltime)
{
    this->nume = nume;
    this->cnp = cnp;
    this->inaltime = inaltime;
}

bool Persoana::operator<(Persoana p)
{
    return this->inaltime < p.inaltime;
}

bool Persoana::operator>(Persoana p)
{
    return this->inaltime > p.inaltime;
}

bool Persoana::operator>=(Persoana p)
{
    return not((*this) < p);
}

bool Persoana::operator<=(Persoana p)
{
    return not((*this) > p);
}

bool Persoana::operator==(Persoana p){
    return ((*this) <= p) and ((*this) >= p);
}

void Persoana::operator=(Persoana &p)
{
    if (this != &p)
    {
        this->nume = p.nume;
        this->cnp = p.cnp;
        this->inaltime = p.inaltime;
    }
}

ostream &operator<<(ostream &out, Persoana &p)
{
    out << "nume: " << p.nume << "\n";
    out << "cnp: " << p.cnp << "\n";
    out << "inaltime: " << p.inaltime;

    return out;
}
