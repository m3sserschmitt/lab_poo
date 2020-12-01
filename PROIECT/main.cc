#include "core/include/notebook.h"
#include "core/include/note.h"
#include "data_structures/iterable/vector/vector.h"
#include "data_structures/iterable/queue/queue.h"
#include "data_structures/iterable/queue/p_priority_queue.h"

#include <iostream>
#include <list>

using namespace std;
/*
void menu()
{
    string input;
    Notebook notebook;

    while (input != "exit")
    {
        cout << ">> ";
        getline(cin, input);

        if (input == "add")
        {
            Event e;
            cin >> e;

            notebook.add(e);
        }
        else if (input == "list")
        {
            Iterator<Event> it = notebook.begin();

            for (; not it.out_of_range(); it.next())
            {
                cout << "#" << it.index() << ": " << it.value() << endl;
            }
        }
        else if (strstr(input.c_str(), "remove"))
        {
            strtok((char *)input.c_str(), " ");

            int index = atoi(strtok(NULL, " "));

            notebook.remove(index);
        }
    }
}
*/


int main()
{
    Notebook notebook;

    // Event *e1 = new Event();

    // cin >> *e1;

    // cout << *e1 << endl;

    cout << "citeste nota: " << endl;

    Note *note = new Note();

    cin >> *note;

    // cout << *note << endl;

    cout << "citeste eveniment: " << endl;

    Event *event = new Event();

    cin >> *event;

    // cout << *event << endl;

    notebook << *event;
    notebook << *note;

    Iterator<Event *> it = notebook.begin();

    for(; not it.out_of_range(); it.next())
    {
        cout << *it.value() << endl;
    }

    // e1->set_name("event1");
    // e1->set_date(Date(13, 3, 2021));
    // e1->set_time(Time(23, 30));

    // Event *e2 = new Event;

    // e2->set_name("event2");
    // e2->set_date(Date(13, 3, 2021));
    // e2->set_time(Time(23, 30));

    // notebook.add(e1);
    // notebook << e2;

    // cout << notebook << endl;

    // Iterator<Event *> it = notebook.begin();

    // for(; not it.out_of_range(); it.next())
    // {
    //     cout << *it.value() << endl;
    // }

    return 0;
}