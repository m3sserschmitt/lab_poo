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

#include <iostream>
#include <sstream>
#include <iomanip>
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
/*
class entry : public Comparable<entry>
{
protected:
    int i;

public:
    entry(int i) : i(i) {}

    virtual int compare(entry *e)
    {
        if (i < e->i)
        {
            return -1;
        }
        else if (i > e->i)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool operator<(entry &e)
    {
        return this->compare(&e) < 0;
    }

    bool operator>(entry &e)
    {
        return this->compare(&e) > 0;
    }

    bool operator<=(entry &e)
    {
        return not(*this > e);
    }

    bool operator>=(entry &e)
    {
        return not(*this < e);
    }
};

class note : public entry
{
public:
    note(int i) : entry(i) {}

    int compare(entry *e)
    {
        return entry::compare(e);
    }
};

class event : public entry
{
protected:
    int _compare(event *e)
    {
        if (e->i > this->i and e->j > this->j)
        {
            return -1;
        }
        else if (e->i < this->i and e->j < this->j)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int j;

public:
    event(int i, int j) : entry(i), j(j) {}

    int compare(entry *e)
    {
        event *ev = dynamic_cast<event *>(e);
        if (ev)
        {
            return this->_compare(ev);
        }

        return entry::compare(e);
    }

};
*/

int main()
{
    // int x = 2;
    // int y = 255;

    // cout << showbase      // show the 0x prefix
    //      << internal      // fill between the prefix and the number
    //      << setfill('0'); // fill with 0s

    // cout << hex << setw(4) << x;

    // stringstream ss;

    // cout << std::showbase
    //    << std::internal
    //    << std::setfill('0');

    //    cout << std::hex
    //    << std::setw(4) << 1;

    // cout << ss.str() << endl;

    // menu();
    // Date("32.11.fsd");

    Time t("23:59:59");

    cout << t << endl;

    cin >> t;

    cout << t << endl;

    return 0;
}