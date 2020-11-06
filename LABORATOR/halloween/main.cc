#include "decoratiune.h"
#include "lista_produse.h"

using namespace std;

int main()
{
    Decoratiune a("lumanari", 10, "rosu", false); 
    Decoratiune b("globuri", 11, "albastru", true);

    ListaProduse lista;

    lista = lista + a;
    lista = lista + b;

    cout << "pret prima decoratiune: " << lista[1].pret() << endl;
    cout << "pret_total: " << lista.pret() << endl;

    cout << "listare produse: " << endl;
    cout << lista << endl;

    lista.remove(1);

    cout << "S-a eliminat un primul element" << endl;

    cout << lista << endl;

    // b = b + a;

    return 0;
}