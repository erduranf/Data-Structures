//This program tests various operations of a linked stack

#include <iostream>
#include "linkedStack.h"

using namespace std;

int main()
{
	linkedStackType<int> newStack;
	linkedStackType<int> newStackCopy;
	linkedStackType<char> charStack;
	linkedStackType<char> charStackCopy;

	newStack.push(1);
	newStack.push(2);
	newStack.push(3);
	newStack.push(2);
	newStack.push(1);

	newStackCopy = newStack;

	cout << "newStack: " << endl;

	//Output the elements of newStack
	while (!newStack.isEmptyStack())
	{
		cout << newStack.top() << endl;
		newStack.pop();
	}

	if (newStackCopy.isPalindrome(newStackCopy))
		cout << "Palindrome..." << endl << endl;
	else cout << "NOT Palindrome..." << endl << endl;

	newStack.push(1);
	newStack.push(2);
	newStack.push(3);
	newStack.push(4);
	newStack.push(5);

	newStackCopy = newStack;

	cout << "newStack: " << endl;

	//Output the elements of newStack
	while (!newStack.isEmptyStack())
	{
		cout << newStack.top() << endl;
		newStack.pop();
	}

	if (newStackCopy.isPalindrome(newStackCopy))
		cout << "Palindrome..." << endl << endl;
	else cout << "NOT Palindrome..." << endl << endl;

	charStack.push('m');
	charStack.push('a');
	charStack.push('d');
	charStack.push('a');
	charStack.push('m');

	cout << "charStack: " << endl;

	charStackCopy = charStack;

	//Output the elements of charStack
	while (!charStack.isEmptyStack())
	{
		cout << charStack.top() << endl;
		charStack.pop();
	}

	if (charStackCopy.isPalindrome(charStackCopy))
		cout << "Palindrome..." << endl << endl;
	else cout << "NOT Palindrome..." << endl << endl;


	cin.get();
}