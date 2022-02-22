#include <iostream>
#include <vector>

using namespace std;

template<class T>
ostream &operator<<(ostream &os, vector<T> v)
{
	os << '[';
	if (v.size() > 0) {
		for (unsigned int i = 0; i < v.size() - 1; i++)
			os << v[i] << ", ";
		os << v[v.size() - 1];
	}
	os << ']';

	return os;
}

vector<int> return_elements(vector<int> &v, int sum)
{
	int current_sum;

	for (unsigned int i = 0; i < v.size(); i++)
		for (unsigned int j = i + 1; j < v.size(); j++) {
			current_sum = v[i] + v[j];
			if (current_sum == sum)
				return vector<int>({v[i], v[j]});
		}

	cout << "A sum of two elements cannot be found." << endl;

	return vector<int>();
}

int main()
{
	vector<int> w = { 1, 4, 2, 5, 3, 8, 7 };
	int sum = 7;

	vector<int> result;
	result = return_elements_1(w, sum);

	cout << result << endl;

	return 0;

}
