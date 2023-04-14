//	2022110879 Á¤Ã¤È²
#include "stacklnk.cpp"
#include <string>

double evaulate(string& postExpression)
{
	Stack<double> postfixStack;
	double operand1, operand2, result;
	for (char c : postExpression) {
		switch (c) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			postfixStack.push(c - '0');
			break;
		case '+':
			operand2 = postfixStack.pop();
			operand1 = postfixStack.pop();
			result = operand1 + operand2;
			postfixStack.push(result);
			break;
		case '-':
			operand2 = postfixStack.pop();
			operand1 = postfixStack.pop();
			result = operand1 - operand2;
			postfixStack.push(result);
			break;
		case '*':
			operand2 = postfixStack.pop();
			operand1 = postfixStack.pop();
			result = operand1 * operand2;
			postfixStack.push(result);
			break;
		case '/':
			operand2 = postfixStack.pop();
			operand1 = postfixStack.pop();
			result = operand1 / operand2;
			postfixStack.push(result);
			break;
		default:
			break;
		}
	}
	return postfixStack.pop();
}

int main(void)
{
	while (cin)
	{
		string postExpression;
		cout << "Input postfix expression: ";
		cin >> postExpression;

		if (!cin)              // Reached EOF: stop processing
			break;

		cout << "result: " << evaulate(postExpression) << endl << endl;
	}

	return 0;
}