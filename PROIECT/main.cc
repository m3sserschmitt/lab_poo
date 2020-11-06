#include "events/time.h"
#include "util/time.h"
#include "events/date.h"
#include "events/event.h"
#include "events/notebook_entry.h"
#include "data_structures/vector/vector.h"
#include "data_structures/queue/priority_queue.h"
#include "events/notebook.h"

#include <iostream>

using namespace std;

int main()
{
    Vector<int> u;
    u << 1 << 3 << 2 << -100 << 0 << 500;

    Vector<int> v = u;

    // u.clear();

    cout << u << endl;
    cout << v << endl;

    return 0;
}