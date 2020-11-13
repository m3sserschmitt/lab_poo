#include "student.h"

using namespace std;

int main()
{
    Persoana p1("Bob", "37294872344", 1.75);
    Persoana p2("Max", "63987494928", 1.85);

    cout << p1 << endl << "------------" << endl;
    cout << p2 << endl << "------------" << endl;

    cout << "p1 < p2: " << (p1 < p2) << endl;

    int note_p1[] = {7, 8, 4, 9};
    int note_p2[] = {10, 10, 9, 8};

    Student s1(p1, "fmi", true, note_p1, 4);
    Student s2(p2, "fmi", false, note_p2, 4);

    cout << s1 << endl << "------------" << endl;
    cout << s2 << endl << "------------" << endl;

    cout << "s1 < s2: " << (s1 < s2) << endl;

    return 0;
}