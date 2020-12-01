#include "./include/notebook.h"

Notebook::Notebook()
{
    this->reserve(0);
    this->current_size = 0;
}

Notebook::Notebook(size_t size)
{
    this->reserve(size);
    this->current_size = 0;
}

Notebook::Notebook(const Notebook &n)
{
    if(this != &n)
    {
        this->reserve(n.size);
        this->set_data(n.data, n.current_size);
    }
}

void Notebook::remove(size_t index)
{
    SubscriptableCollection::remove(index);
}

Vector<Event *> list(Date d)
{

}

// ssize_t Notebook::search(Event *elem, ssize_t i, ssize_t j, ssize_t *l)
// {
//     ssize_t k = (i + j) / 2;

//     if (i >= j)
//     {
//         if (l)
//         {
//             *l = k + (elem->compare(this->data[k]) > 0);
//             // *l = k + (elem > this->data[k]);
//         }

//         return not elem->compare(this->data[k]) ? k : -1;
//         // return elem == this->data[k] ? k : -1;
//     }
//     // else if (elem < this->data[k])
//     else if(elem->compare(this->data[k]) < 0)
//     {
//         return this->search(elem, i, k, l);
//     }
//     // else if (elem > this->data[k])
//     else if (elem->compare(this->data[k]) > 0)
//     {
//         return this->search(elem, k + 1, j, l);
//     }
//     else
//     {
//         if (l)
//         {
//             *l = k + 1;
//         }

//         // while (k > 0 and this->data[k] == elem and this->data[k - 1] == elem)
//         while (k > 0 and not elem->compare(this->data[k]) and not elem->compare(this->data[k - 1]))
//         {
//             k--;
//         }

//         return k;
//     }
// }

std::ostream &operator<<(std::ostream &out, Notebook &n)
{

    out << "[Notebook: ";

    if (not n.get_size())
    {
        out << "no entries]";
    }
    else if (n.get_size() == 1)
    {
        out << 1 << " entry]";
    }
    else
    {
        out << n.get_size() << " entries]";
    }

    return out;
}

Notebook &operator<<(Notebook &n, Event &e)
{
    n.add(&e);
    return n;
}