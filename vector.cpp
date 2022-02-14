#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>);
vector<int> sample(vector<int>, unsigned int, bool);

// operator overloading.
template<class T>
ostream& operator<<(ostream &os, vector<T> &v)
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

void bubble_sort(vector<int> &w)
{
	int temp;
	unsigned int size = w.size();
	for (unsigned int i = 0; i < size - 1; i++)
	        for (unsigned int j = 0; j < size - 1; j++)
	                if (w[j] > w[j + 1]) {
	                        temp = w[j + 1];
	                        w[j + 1] = w[j];
	                        w[j] = temp;
	                }
}

vector<int> sample(vector<int> &from, unsigned int k, bool replace)
{
	int random_index;
	int to_add;

	if ((!replace) && (k >= from.size())) {
		cout << "ERROR: sampling with no replacement not possible." << endl;
		return vector<int>();
	}

	vector<int> output;
	vector<int> from_copy = from; // this operator is overloaded to allow deep copy.

	for (unsigned int i = 0; i < k; i++) {
		random_index = rand() % from_copy.size();
		to_add = from_copy[random_index];

		if (replace == false)
			from_copy.erase(from_copy.begin() + random_index); // delete the index-th element.

		output.insert(output.end(), to_add);

		if (from_copy.size() == 0)
			break;
	}

	return output;
}

int main()
{
	int el;

	vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int> w = sample(v, 5, true);

	cout << w << endl;
	
	// Insert to the beginning
	v.insert(v.begin(), 6);

	// Insert to the end
	v.insert(v.end(), { 10 });

	// Remove first element
	el = v[0];
	cout << "First element is: " << el << endl;
	v.erase(v.begin());

	// Remove the third element:
	cout << v << endl;
	v.erase(v.begin() + 3);
	cout << v << endl;

	// Read last element
	el = v[v.size() - 1];
	cout << "Last element is: " << el << endl;

	cout << v << endl;

	return 0;
}
