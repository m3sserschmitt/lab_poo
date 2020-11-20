#include "lista_produse.h"


int main()
{
    ProdusNeperisabil pn, pn1;
    ProdusPerisabil pp;

    ListaProduse l;

    
    cin >> pn;
    cin >> pn1;
    cin >> pp;

    l.adauga_produs_neperisabil(pn);
    l.adauga_produs_neperisabil(pn1);
    l.adauga_produs_perisabil(pp);

    cout << "lista contine: " << endl;
    cout << l << endl;

    cout << endl;

    cout << "pretul pentru primul produs: " << l[0].calculeazaPret() << endl;
    cout << "pretul pentru al doilea produs: " << l[1].calculeazaPret() << endl;
    cout << "pretul pentru al trilea produs: " << l[2].calculeazaPret() << endl;

    l.sterge_produs(1);

    cout << "lista contine (dupa stergere): " << endl;

    cout << l << endl;

    return 0;
}