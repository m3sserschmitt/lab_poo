#include "./exceptions/include/exception.h"

#include "./include/menu.h"

#include <fstream>

using namespace std;

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

static list<Entry *> list_range(vector<string> arguments, int i, Notebook &notebook, DateRange &range)
{
    if (not notebook.get_size())
    {
        return {};
    }

    Date begin;
    Date end;

    int argc = arguments.size();

    switch (argc - i)
    {
    case 0:
        begin = notebook.get_first_date();
        end = notebook.get_last_date();
        break;
    case 1:
        begin.set_date(arguments[i].c_str());
        end.set_date(arguments[i].c_str());
        break;
    default:
        begin.set_date(arguments[i].c_str());
        end.set_date(arguments[i + 1].c_str());
    }

    range.set_begin(begin);
    range.set_end(end);

    return notebook.list(range);
}

void list_entries(vector<string> arguments, Notebook &notebook)
{
    if (arguments.size() > 3)
    {
        cout << "[-] Error: Wrong number of arguments for command \'" << arguments[0] << "\'.\n";
        return;
    }

    DateRange range;
    list<Entry *> entries = list_range(arguments, 1, notebook, range);

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

void export_entries(vector<string> arguments, Notebook &notebook)
{
    if (arguments.size() < 2 or arguments.size() > 4)
    {
        cout << "[-] Error: Wrong number of arguments for command \'" << arguments[0] << "\'.\n";
        return;
    }

    DateRange range;
    list<Entry *> entries = list_range(arguments, 2, notebook, range);

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

void import_entries(vector<std::string> arguments, Notebook &notebook)
{
    if (arguments.size() < 2 or arguments.size() > 4)
    {
        cout << "[-] Error: Wrong number of arguments for command \'" << arguments[0] << "\'.\n";
        return;
    }

    ifstream file(arguments[1]);

    if (not file.is_open())
    {
        cout << "[-] Error: failed to open file \'" << arguments[1] << "\'.\n";
        return;
    }

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
        notebook << *entry;
    }
}

void remove(vector<string> arguments, Notebook &notebook)
{
    size_t index;
    switch (arguments.size())
    {
    case 2:
        index = atol(arguments[1].c_str());

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
