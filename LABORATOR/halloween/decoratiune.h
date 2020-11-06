#ifndef DECORATIUNE_H
#define DECORATIUNE_H

#include <iostream>

class Decoratiune
{
    float pret_decoratiune;
    bool decoratiune_reciclabila;

    std::string nume_decoratiune;
    std::string culoare_decoratiune;

public:
    Decoratiune();
    Decoratiune(const Decoratiune &d);
    Decoratiune(std::string nume, float pret, std::string culoare, bool reciclabil);

    void seteaza_nume(std::string nume);
    std::string nume();

    void seteaza_culoare(std::string culoare);
    std::string culoare();

    void seteaza_pret(float pret);
    float pret();

    void seteaza_reciclabil(bool reciclabil);
    bool reciclabil();

    friend std::ostream &operator<<(std::ostream &, Decoratiune &);

};

#endif