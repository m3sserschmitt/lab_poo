#include "notebook.h"
#include "note.h"

#include <vector>
#include <string>

using namespace std;

void add(vector<string> arguments, Notebook &notebook);
void list_entries(vector<string> arguments, Notebook &notebook);
void remove(vector<string> arguments, Notebook &notebook);