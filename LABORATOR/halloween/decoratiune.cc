#include "decoratiune.h"

Decoratiune::Decoratiune()
{
}

Decoratiune::Decoratiune(const Decoratiune &d)
{
    this->nume_decoratiune = d.nume_decoratiune;
    this->culoare_decoratiune = d.culoare_decoratiune;
    this->pret_decoratiune = d.pret_decoratiune;
    this->decoratiune_reciclabila = d.decoratiune_reciclabila;
}

Decoratiune::Decoratiune(std::string nume, float pret, std::string culoare, bool reciclabil)
{
    this->nume_decoratiune = nume;
    this->pret_decoratiune = pret;
    this->culoare_decoratiune = culoare;
    this->decoratiune_reciclabila = reciclabil;
}

void Decoratiune::seteaza_nume(std::string nume){
    this->nume_decoratiune = nume;
}

std::string Decoratiune::nume(){
    return this->nume_decoratiune;
}

void Decoratiune::seteaza_culoare(std::string culoare)
{
    this->culoare_decoratiune = culoare;
}

std::string Decoratiune::culoare()
{
    return this->culoare_decoratiune;
}

void Decoratiune::seteaza_pret(float pret)
{
    this->pret_decoratiune = pret;
}

float Decoratiune::pret()
{
    return this->pret_decoratiune;
}

void Decoratiune::seteaza_reciclabil(bool reciclabil)
{
    this->decoratiune_reciclabila = reciclabil;
}

bool Decoratiune::reciclabil()
{
    return this->decoratiune_reciclabila;
}

std::ostream &operator<<(std::ostream &out, Decoratiune &d)
{
    out << "nume: " << d.nume() << ", culoare: " << d.culoare() << ", pret: " << d.pret() << ", reciclabil: " << d.reciclabil();

    return out;
}