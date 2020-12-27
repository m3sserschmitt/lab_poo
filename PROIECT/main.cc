#include "core/include/notebook.h"
#include "core/include/note.h"
#include "data_structures/iterable/vector/vector.h"
#include "data_structures/iterable/queue/queue.h"
#include "data_structures/iterable/queue/p_priority_queue.h"
#include "./core/include/menu.h"
#include "./core/include/date_range.h"

#include "./util/include/util.h"
#include "./util/include/time.h"
#include "./core/exceptions/include/invalid_date.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <list>
#include <map>

using namespace std;

void menu()
{
    string input;
    Notebook notebook;

    do
    {
        cout << ">> ";
        getline(cin, input);

        if(not input.size())
        {
            continue;
        }

        vector<string> arguments = split(input, " ", -1);

        if (arguments[0] == "add")
        {
            add(arguments, notebook);
        }
        else if (arguments[0] == "list")
        {
            list_entries(arguments, notebook);
        }
        else if (arguments[0] == "import")
        {
            import_entries(arguments, notebook);
        }
        else if (arguments[0] == "export")
        {
            export_entries(arguments, notebook);
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

    // map<string, string> m = {{"Name", "test"}, {"Date", "date"}};

    // cout << m["name"] << endl;
    // cout << m["Date"] << endl;

    return 0;
}