#include "./include/menu.h"

vector<string> split(string str, string sep, int max_split)
{
    vector<string> tokens;

    size_t sep_pos;
    int split_index = 0;

    if (!str.size())
        return tokens;

    tokens.reserve(10);

    do
    {
        split_index++;
        sep_pos = str.find(sep);

        // tokens.resize(tokens.size() + 1);
        tokens.push_back(str.substr(0, sep_pos));
        if (sep_pos == string::npos)
        {
            // tokens.resize(split_index);
            return tokens;
        }

        str = str.substr(sep_pos + sep.size());
        if (split_index == max_split && str.size())
        {

            // tokens.resize(tokens.size() + 1);
            tokens.push_back(str);
            // tokens.resize(split_index + 1);
            return tokens;
        }
    } while (true);

    return tokens;
}

void add(vector<string> arguments, Notebook &notebook)
{
    Event *e;

    switch (arguments.size())
    {
    case 1:
        e = new Event();
        break;
    case 2:
        if (arguments[1] == "event")
        {
            e = new Event();
        }
        else if (arguments[1] == "note")
        {
            e = new Note();
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

    cin >> *e;
    notebook << *e;

    cout << "[+] OK: Entry added.\n"; 
}

void list_entries(vector<string> arguments, Notebook &notebook)
{
    Iterator<Event *> it = notebook.begin();

    cout << notebook << "\n\n";

    for(; not it.out_of_range(); it.next())
    {
        cout << "#" << it.index() << " " << *it.value() << "\n\n";
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