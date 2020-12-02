## Romulus-Emanuel Ruja, grupa 212.

## PROIECT

Aplicatia este un notebook in care se pot introduce evenimente ce sunt ordonate dupa data.

### Update, etapa II:

S-au facut urmatoarele modificari:
* S-a reorganizat codul sursa (+ alte modificari la implementare si am rezolvat cateva bug-uri).
* In `data_structures/abstract` am adugat clasa `Comparable`.
* S-a modificat ierarhia claselor, intrucat am introdus clasa `SuscriptableCollection` care este in mare parte un `Collection` ce suporta indexarea (`operator[](size_t)`). Astefel restul tipurilor (i.e. `Vector`, `Queue`, `PriorityQueue`) sunt derivate din clasa `SubscriptableCollection` si nu din `Collection`, cum se intampla in prima etapa. 
* Pentru clasa `PriorityQueue` am introdus o specializare partiala pentru pointeri de tipul `Comparable` (i.e suporta orice tip derivat din clasa `Comparable`)
* Am introdus clasa `Note` derivata din clasa `Event` in `core/include`.
* Acum, din meniul principal se pot introduce intrari de tipul `Event` si, in plus fata de prima etapa, intrari de tipul `Note` Altfel spus, command `add` poate fi folosita acum `add note`, `add event` sau simplu `add` (daca nu se specifica, va fi `event`). Alte functionalitati urmeaza sa fie introduse...

### Etapa I

Momentan, meniul interactiv are doar 3 comenzi:

* add - introduce un nou eveniment.
* list - listeaza toate evenimentele introduse.
* remove 'index' - sterge un eveniment (indexate de la 0).

*_IDE: Visual Studio Code_*

*_Daca exista probleme la compilare, am pus si un executabil Windows, intrucat eu folosesc Linux. Am folosit si un cross compiler pentru a vedea daca intr-adevar codul este cross-platform si nu au fost probleme._*