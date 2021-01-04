## Romulus-Emanuel Ruja, grupa 212.

___

## PROIECT

Aplicația este un notebook în care se pot introduce evenimente ce sunt ordonate dupa dată.

___

### Update, Design Pattern: Singleton.

Având în vedere că în aplicație se folosește o __*singură instanță*__ a clasei `Notebook`, are sens modificarea sa în vederea implementării unui *singleton*.

Modificările sunt după cum urmează:

* în `core/include/notebook.h` s-a modificat definiția clasei astel încât toți contructorii și operatorul de atribuire sunt acum declarate __*private*__.
* s-a adăugat metoda statică `getHandle`, care atunci când este apelată crează static o instanță `Notebook` și returnează o referință la aceasta (`/core/notebook.cc`, linia 25).
* în meniul principal, se apelează metoda `getHandle` pentru a obține o referință la unicul obiect `Notebook` (`main.cc`, linia 25).
___

### Update, etapa III:

__Structura finală__:

* `core`:
    * `exceptions`: excepții.
    * `include`: conține fișiere header în care sunt definite clasele de bază ale aplicației.
    * restul fișierelor `.cc` reprezintă implementările claselor definite în directorul `include`.

* `data_structures`:
    * `abstract`: conține fișiere header în care sunt definite următoarele clase abstracte/interfețe (__toate sunt template-uri__)
        * `Collection` (`collection.h`, __*clasă abstractă*__, derivată din `Iterable`): clasă de tip container în care s-au implementat metode de bază pentru alocarea/ștergerea memoriei, adăugarea elementelor etc.  

        * `Comparable` (`comparable.h`, __*interfață*__): conține metoda virtuală pură `compare` și toți operatorii de comparație (operatori logici). Practic, toate obiectele care se pot compara, definite în acest proiect, sunt derivate din această interfată (e.g. `Event`, `Note`, `Vector`) și vor face *overload*, pe metoda virtuală `compare`.

        * `Iterable` (`iterable.h`, __*interfață*__): conține două metode virtuale pure ce returnează iteratori.

        * `Iterator` (`iterator.h`): implemetată pentru a ajuta la iterarea peste obiectele derivate din `Iterable` (e.g. `Vector`, `Queue`, `Notebook` etc).
    
    * `collection`: conține fișierul header `subscriptable_collection.h` în care s-a definit clasa `SubscriptableCollection` ce suportă indexarea, în plus fața de `Collection`.

    * `iterable`: conține clase de tip container (__toate sunt template-uri__)
        * `queue`:
            * `Queue` (`queue.h`): implementează o "coadă".

            * `PriorityQueue` (`priority_queue.h`): implementează o "coadă" în care elementele sunt ordonate după prioritate. `p_priority_queue.h` definește o specializare parțială pentru elemente pointeri.
        
        * `vector`:
            * `Vector` (`vector.h`), a fost implementată deoarece aveam nevoie de un obiect care să implemeteze ordinea lexico-grafică, necesară la compararea obiectelor de tip `Date` sau `Time`, așa cum se poate vedea, de exemplu în `core/date.cc` în metoda `compare` la linia 54.

* `util`: aici s-au definit câteva funcții ajutătoare.

# Cum funcționează?

S-a contruit urmatoarea ierarhie de clase:

`Iterable<Entry *>` -> `Collection<Entry *>` -> `SubscriptableCollection<Entry *>` -> `Queue<Entry *>` -> `PriorityQueue<Entry *>` -> `Notebook`.

`Notebook` este clasă de tip container în care sunt stocate toate detele aplicației. Acceptă __pointeri la obiecte derivate__ din clasa `Entry`.

Clasa `Entry` (__*clasă abstractă*__), derivată din `Comparable` (__*interfață*__) reprezintă *"tipul de bază"* cu care se lucrează în aplicație. Din aceasta s-au derivat clasele `Event` și `Note`.

Așa cum am mai spus, orice clasă derivată din `Comparable` (care nu se vrea a fi la rândul ei interfață), trebuie să facă *overload* pe metoda `compare`. Voi lua ca exemplu clasa `Event` (`/core/include/event.h`) pentru a explica mecanismul de comparare.

Am considerat că `event1` < `event2`, dacă `event1` are o *"dată mai mică"* decât `event2` și un *"timp mai mic"* decăt `event2`. De exemplu 30.12.2020 este o *"dată mai mică"* decât 02.01.2021, iar 20:30 este *"un timp mai mic"* decăt 22:00. Clasele `Date` (`core/include/date.h`) și `Time` (`/core/include/time.h`) sunt de asemenea derivate din `Comparable` și fac *overload* pe metoda `compare`. 

În definiția clasei `Comparable` (`data_structures/abstract/comparable.h`, de la linia 34 la linia 44) se obervă că operatorii '<' și '>' folosesc __metoda virtuală__ `compare` pentru a determina daca `c1` < `c2` sau invers.

Prototipul metodei `compare` din clasa `Event` este:

`int Event::compare(const Entry &e) const`

(`core/event.cc`, linia 95)

Acolo se încearcă mai întai un `dynamic_cast` pentru a se determina tipul obiectului cu care se compară. Dacă se compară cu un obiect de tip `Event`, atunci se compară data și ora, iar dacă se compară cu un obiect de tip `Note`, atunci se rezumă la compararea datei. Tot aici se vede și de ce e folositoare clasa `Vector` și ordinea lexicografică (a se vedea si metodele `compare` din implementate în `/core/date.cc` și `core/time.cc`, pentru clasele `Date` și `Time`). Alfel spus, fiecare clasă ce moșteneșe interfața `Comparable` își definește propriul mod de comparare facând __*overload* pe metoda `compare`__.

În final, în clasa `Notebook`, fiind derivată din `PriorityQueue` se consideră că `entry1` are prioritate mai mare decât `entry2`, dacă `entry1` < `entry2`. Intrările cu prioritate mare sunt la începutul cozii în timp ce intrările cu prioritate mai mică se află la capătul ei.

___

__Meniul__ are acum urmatoarele comenzi (tot ce este între "[" și "]" este opțional):
* __add [ *event* | *note* ]__: adaugă o nouă intrare. (*event*, dacă nu se specifică).
* __list [ *date1* [ *date2* ] ]__: listează toate avenimentele dacă nu se specifică altceva, evenimentele din ziua respectivă daca se specifică *date1* sau toate evenimentele din intervalul *[date1, date2]* dacă sunt introduse ambele.
* __remove *index*__: șterge evenimentul cu indexul corespunzător (indexarea începe de la 0).
* __import *file* [ *date1* [ *date2* ] ]__: importă evenimente din fișierul *file*, *date1* și *date2* au aceeași semnificație ca la comanda __*list*__.
* __export *file* [ date1 [ date2 ] ]__: exportă evenimente în fișierul *file*, *date1* și *date2* având aceeași semnificație ca la comanda __*list*__.
* __clear__: șterge toate intrările din aplicație.
* __exit__: închide aplicația.

Funcția `menu` se gasește în `main.cc` iar implementarea funcțiilor din meniu se află în `core/menu.cc`.

___

### Update, etapa II:

S-au făcut următoarele modificări:
* S-a reorganizat codul sursă (+ alte modificări la implementare și am rezolvat câteva bug-uri).
* În `data_structures/abstract` am adăugat clasa `Comparable`.
* S-a modificat ierarhia claselor, întrucât am introdus clasa `SuscriptableCollection` care este în mare parte un `Collection` ce suportă indexarea (`operator[](size_t)`). Astfel restul tipurilor (i.e. `Vector`, `Queue`, `PriorityQueue`) sunt derivate din clasa `SubscriptableCollection` și nu din `Collection`, cum se întâmpla în prima etapă. 
* Pentru clasa `PriorityQueue` am introdus o specializare parțială pentru pointeri de tipul `Comparable` (i.e suportă orice tip derivat din clasa `Comparable`)
* Am introdus clasa `Note` derivată din clasa `Event` in `core/include`.
* Acum, din meniul principal se pot introduce intrări de tipul `Event` și, în plus față de prima etapă, intrări de tipul `Note`. Altfel spus, comanda `add` poate fi folosită acum `add note`, `add event` sau simplu `add` (dacă nu se specifică, va fi `event`). Alte functionalități urmează să fie introduse...

___

### Etapa I

Momentan, meniul interactiv are doar 3 comenzi:

* add - introduce un nou eveniment.
* list - listează toate evenimentele introduse.
* remove 'index' - șterge un eveniment (indexate de la 0).

___

*_IDE: Visual Studio Code_*

*_Dacă există probleme la compilare, am pus și un executabil Windows (`build/notebook.exe`), intrucât eu folosesc Linux. Am folosit si un cross compiler pentru a vedea dacă într-adevar codul este cross-platform și nu au fost probleme._*

___

### LICENȚĂ: 

Open source, [MIT License](LICENSE).
