#include "core/include/notebook.h"

#include <iostream>

using namespace std;

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

int main()
{
    menu();
    
    return 0;
}