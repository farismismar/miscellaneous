#include <iostream>
#include <string>

using namespace std;

template<typename T, size_t arrSize, 
    typename=enable_if_t<!is_same<T,char>::value>>
ostream &operator<<(ostream &os, const T(&array)[arrSize])
{
    os << "[";
    for (int i = 0; i < arrSize; i++) {
        os << array[i];
        if (i != arrSize - 1)
            os << ", ";
    }
    os << "]";
    
    return os;
}

int main() {
    char *strings[] = {"test", "one", "is", "here"};
    string strings_cpp[] = {"test", "two"};
    int array[] = {1, 2, 3};
    
    cout << strings << endl;
    cout << strings_cpp << endl;
    cout << array << endl;
    
    return 0;
}
