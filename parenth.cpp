#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool match_my_string(string &input_string)
{
	stack<char> parenthesis_stack;
	char last_parenthesis;
	unsigned int i;

	for (i = 0; i < input_string.size(); i++) {
		if (input_string[i] == '(')
			parenthesis_stack.push(input_string[i]);
		else if (input_string[i] == ')') {
			last_parenthesis = parenthesis_stack.top();
			parenthesis_stack.pop();
		}
	}

	if (parenthesis_stack.empty())
		return true;
	else
		cout << "Mismatch detected.  Check parenthesis at location " << i << endl;
		return false;
}

int main()
{
	string input_string = "(1+2*(3+4)-5)";
	bool result = false;

	result = match_my_string(input_string);

	if (result)
		cout << "Parentheses match.  Good job!" << endl;

	return (0);
}