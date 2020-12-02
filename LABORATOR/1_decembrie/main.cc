#include "masina_interventie.h"
#include "masina_receptie.h"
#include "masina_undercover.h"
#include "lista_automobile.h"


int main()
{
    MasinaUndercover mu("dacia", "logan", "misiuni sub acoperire", 280, 700);
    MasinaInterventie mi("bmw", "m6", "interventii in forta", 6, true);
    MasinaReceptie mr("opel", "corsa", "spionaj", 100, 80);

    ListaAutomobile l;

    l = l + mu;
    l = l + mi;
    l = l + mr;

    size_t k = l.dimensiune();
    
    for(size_t i = 0; i < k; i ++)
    {
        l[i]->afisare();
        cout << "\n";
    }

    return 0;
}