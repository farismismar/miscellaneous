#include <iostream>
#include <string>

using namespace std;

bool is_unique(string &s)
{
    for (int i = 0; i < s.size(); i++) {
        char current_char = s.at(i);
        for (int j = 0; j < s.size(); j++) {
            if (j == i) continue;
            if (current_char == s.at(j)) return false;
        }
    }
    return true;
}

int main()
{
    string s, t;

    s = "abcdef";
    t = "aabbcc";

    cout << boolalpha << is_unique(s) << endl;
    cout << boolalpha << is_unique(t) << endl;
    
    return 0;
}