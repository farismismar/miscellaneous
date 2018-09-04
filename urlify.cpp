#include <iostream>
#include <string>

using namespace std;

string urlify(string &s)
{
    string output = "";

    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ') {
            output.push_back('%');
            output.push_back('2');
            output.push_back('0');
        }
        else
            output.push_back(s[i]);

    return output;
}

int main()
{
    string url = "http://www.getme.this/url fil e.html";

    cout << urlify(url) << endl;

    return 0;
}
