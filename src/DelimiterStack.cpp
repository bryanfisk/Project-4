#include "DelimiterStack.h"
#include <iostream>
using namespace std;

DelimiterStack::DelimiterStack(int size) {
	stackPtr = new DelimiterNode[size];
	top = -1;
	this->size = size;
}

void DelimiterStack::push(char character, int lineNumber, int charCount) {
	if (isFull()) {
		std::cout << "The stack is full.\n";
	} else {
		top++;
		stackPtr[top].character = character;
		stackPtr[top].lineNumber = lineNumber;
		stackPtr[top].charCount = charCount + 1;
	}
}

void DelimiterStack::popDelimiter(char& character, int& lineNumber, int& charCount){ // reference variables because three variables cannot be returned through return statement
	if (!isEmpty()) {
		character = stackPtr[top].character;
		lineNumber = stackPtr[top].lineNumber;
		charCount = stackPtr[top].charCount;
		top--;
	}
}

bool DelimiterStack::isFull() const{
	bool status;
	if (top == size - 1) {
		status = true;
	} else  status = false;
	return status;
}

bool DelimiterStack::isEmpty() const{
	bool status;
	if (top == -1) {
		status = true;
	} else  status = false;
	return status;
}

DelimiterStack::~DelimiterStack() {
}

