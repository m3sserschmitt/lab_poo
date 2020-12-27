#include "./exceptions/include/exception.h"

#include "./include/menu.h"
#include "../util/include/util.h"

#include <fstream>

using namespace std;

static list<Entry *> list_range(vector<string> arguments, int i, const Notebook &notebook, DateRange &range)
{
    if (not notebook.get_size())
    {
        return {};
    }

    int argc = arguments.size();

    switch (argc - i)
    {
    case 0:
        range.set(notebook.get_first_date(), notebook.get_last_date());
        break;
    case 1:
        range.set(Date(arguments[i]), Date(arguments[i]));
        break;
    default:
        range.set(Date(arguments[i]), Date(arguments[i + 1]));
    }

    return notebook.list(range);
}

void add(vector<string> arguments, Notebook &notebook)
{
    Entry *entry;

    switch (arguments.size())
    {
    case 1:
        entry = new Event();
        break;
    case 2:
        if (arguments[1] == "event")
        {
            entry = new Event();
        }
        else if (arguments[1] == "note")
        {
            entry = new Note();
        }
        else
        {
            cout << "[-] Error: Unknown argument for \'add\' command: \'" << arguments[1] << "\'.\n";
            return;
        }
        break;
    default:
        cout << "[-] Error: Wrong number of arguments.\n";
        return;
        break;
    }

    cin >> *entry;
    notebook << *entry;

    cout << "[+] OK: Entry added.\n";
}

void list_entries(vector<string> arguments, const Notebook &notebook)
{
    if (arguments.size() > 3)
    {
        cout << "[-] Error: Wrong number of arguments for command \'" << arguments[0] << "\'.\n";
        return;
    }

    DateRange range;
    list<Entry *> entries;

    try
    {
        entries = list_range(arguments, 1, notebook, range);
    }
    catch (const Exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    if (not entries.size())
    {
        cout << "[+] No entries to be listed\n";
        return;
    }

    cout << "[+] Listing entries: " << range << ".\n";
    cout << "[+] " << entries.size() << " in total.\n\n";

    list<Entry *>::iterator b = entries.begin();
    list<Entry *>::iterator e = entries.end();

    for (size_t i = 0; b != e; i++, b++)
    {
        cout << "#" << i << " " << **b << "\n\n";
    }
}

void remove(vector<string> arguments, Notebook &notebook)
{
    int index;
    switch (arguments.size())
    {
    case 2:
        if(not is_number(arguments[1], index))
        {
            cout << "[-] Error: Wrong index.\n";
            return;
        }

        try
        {
            notebook.remove(index);
        }
        catch (const Exception &e)
        {
            std::cerr << e.what() << '\n';
            break;
        }

        cout << "[+] OK: Entry removed." << endl;
        break;
    default:
        cout << "[-] Error: Wrong number of arguments for command \'" << arguments[0] << "\'.\n";
        break;
    }
}

// void clear(Notebook &notebook)
// {

// }

void import_entries(vector<std::string> arguments, Notebook &notebook)
{
    if (arguments.size() < 2 or arguments.size() > 4)
    {
        cout << "[-] Error: Wrong number of arguments for command \'" << arguments[0] << "\'.\n";
        return;
    }

    DateRange range;

    try
    {
        switch (arguments.size())
        {
        case 2:
            range.set(Date(1, 1, 1900), Date(31, 12, 3000));
            break;

        case 3:
            range = DateRange(Date(arguments[2]));
            break;

        case 4:
            range.set(Date(arguments[2]), Date(arguments[3]));
            break;

        default:
            cout << "[-] Error: Wrong number of arguments for command \'" << arguments[0] << "\'.\n";
            return;
        }
    }
    catch (const Exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    ifstream file(arguments[1]);

    if (not file.is_open())
    {
        cout << "[-] Error: failed to open file \'" << arguments[1] << "\'.\n";
        return;
    }

    cout << "[+] Importing: " << range << ".\n";

    size_t count = 0;
    string input;

    while (getline(file, input))
    {
        Entry *entry;

        if (input == "[Note]")
        {
            entry = new Note();
        }
        else if (input == "[Event]")
        {
            entry = new Event();
        }

        file >> *entry;

        if (entry->in_range(range))
        {
            notebook << *entry;
            count ++;
        }
        else
        {
            delete entry;
        }
    }

    cout << "[+] " << count << " entries imported in total.\n";
}

void export_entries(vector<string> arguments, const Notebook &notebook)
{
    if (arguments.size() < 2 or arguments.size() > 4)
    {
        cout << "[-] Error: Wrong number of arguments for command \'" << arguments[0] << "\'.\n";
        return;
    }

    DateRange range;
    list<Entry *> entries;

    try
    {
        entries = list_range(arguments, 2, notebook, range);
    }
    catch (const Exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    if (not entries.size())
    {
        cout << "[+] No entries to be listed\n";
        return;
    }

    ofstream file(arguments[1]);

    if (not file.is_open())
    {
        cout << "[-] Error: failed to open file \'" << arguments[1] << "\'.\n";
        return;
    }

    cout << "[+] Exporting entries into file \'" << arguments[1] << "\': " << range << ".\n";
    cout << "[+] " << entries.size() << " in total.\n\n";

    list<Entry *>::iterator b = entries.begin();
    list<Entry *>::iterator e = entries.end();

    for (size_t i = 0; b != e; i++, b++)
    {
        file << **b << "\n\n";
    }

    cout << "[+] Done.\n";
}
