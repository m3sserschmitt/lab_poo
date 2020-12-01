#include "core/include/notebook.h"
#include "core/include/note.h"
#include "data_structures/iterable/vector/vector.h"
#include "data_structures/iterable/queue/queue.h"
#include "data_structures/iterable/queue/p_priority_queue.h"
#include "./core/include/menu.h"

#include <iostream>
#include <list>

using namespace std;

void menu()
{
    string input;
    Notebook notebook;

    do
    {
        cout << ">> ";
        getline(cin, input);

        vector<string> arguments = split(input, " ", -1);

        if (arguments[0] == "add")
        {
            add(arguments, notebook);
        }
        else if (arguments[0] == "list")
        {
            list_entries(arguments, notebook);
        }
        else if (arguments[0] == "remove")
        {
            remove(arguments, notebook);
        }
        else if (arguments[0] != "exit")
        {
            cout << "[-] Error: Unknown command \'" << arguments[0] << "\'.\n";
        }

    } while (input != "exit");
}

int main()
{
    menu();

    return 0;
}