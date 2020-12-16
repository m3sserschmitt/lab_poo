#include "./include/menu.h"


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

void list_entries(vector<string> arguments, Notebook &notebook)
{
    DateRange range;
    Date begin; 
    Date end;

    switch (arguments.size())
    {
    case 2:
        begin.set_date(arguments[1].c_str());
        end.set_date(arguments[1].c_str());
        break;
    case 3:
        begin.set_date(arguments[1].c_str());
        end.set_date(arguments[2].c_str());
        break;
    default:
        begin = notebook.get_first_date();
        end = notebook.get_last_date();
    }

    range.set_begin(begin);
    range.set_end(end);

    list<Entry *> entries = notebook.list(range);

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
    size_t index;
    switch (arguments.size())
    {
    case 2:
        index = atol(arguments[1].c_str());
        notebook.remove(index);

        cout << "[+] OK: Entry removed." << endl;
        break;
    default:
        cout << "[-] Error: Wrong number of arguments for command \'" << arguments[0] << "\'.\n";
        break;
    }
}