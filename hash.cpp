#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hash {
    friend ostream &operator<<(ostream &, Hash &);
private:
    vector<string> *table;
    int hash_size;
public:
    Hash(int size);
    ~Hash();
    int hash_code(const string &);
    void clear();
    bool insert(const string &);
    bool remove(const int, const string &);
};

ostream &operator<<(ostream &os, Hash &h)
{
    for (int i = 0; i < h.hash_size; i++) {
        os << i << ": ";
        for (vector<string>::iterator j = h.table[i].begin(); j < h.table[i].end(); j++)
            os << *j << " ";
        os << endl;
    }

    return os;
}

Hash::Hash(int size)
{
    table = new vector<string> [size];
    hash_size = size;
}

Hash::~Hash()
{
    delete [] table;
    table = nullptr;
}

inline void Hash::clear()
{
    delete [] table;
    table = new vector<string> [hash_size];
}

bool Hash::insert(const string &s)
{
    int hash = hash_code(s);

    table[hash].push_back(s);

    return true;
}

bool Hash::remove(const int key, const string &r) 
{
    vector<string>::iterator p = table[key].begin();

    // Erase the first occurrence only.
    for (; p < table[key].end(); p++)
        if (*p == r) {p->erase(); return true;}

    return false;
}

int Hash::hash_code(const string &str)
{
    int value = 0;
    for (int i = 0; i < str.length(); i++)
        value = value * 4 + (int)(str.at(i) - 'A');
    value = value % hash_size;

    return value;
}

// Driver program
int main()
{
    Hash t(10);

    t.insert("Hello");
    t.insert("Welcome");
    t.insert("Home");
    cout << t << endl;

    t.remove(6, "Home");
    t.remove(5, "Home");
    cout << t << endl;

    t.clear();
    t.insert("Home");
    t.insert("Welcome");
    t.insert("House");
    t.insert("Hello");
    t.insert("Hello");

    cout << t << endl;

    return 0;
}
