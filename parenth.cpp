#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool match_my_string(string &input_string)
{
	stack<char> parenthesis_stack;
	char last_parenthesis;
	unsigned int i;

	bool flag = false;

	for (i = 0; i < input_string.size(); i++) {
		if (input_string[i] == '(')
			parenthesis_stack.push(input_string[i]);
		else if (input_string[i] == ')') {
			if (parenthesis_stack.empty()) {
				flag = true;
				break;
			}

			parenthesis_stack.pop();
		}
	}

	if (flag == true)
		return false;

	return parenthesis_stack.empty();		
}

int main()
{
	string input_string = "(1+2*3)+4*((3-5))";
	bool result = false;

	result = match_my_string(input_string);

	if (result)
		cout << "Parentheses match.  Good job!" << endl;
	else
		cout << "Mismatch detected." << endl;

	return (0);
}