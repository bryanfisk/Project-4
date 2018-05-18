#include<iostream>
#include<string>
#include "DelimiterStack.h"
using namespace std;

struct characterHolder { //struct for holding the information of a delimiter character popped off the stack.
	char character;
	int line;
	int characterNum;
};

void delimiterCheck(char, int, int, string, characterHolder*, DelimiterStack*);
char matchingDelimiter (char);

int main() {
	// variable declarations and initializations
	DelimiterStack * stack = new DelimiterStack(20);
	string currentLine = "";
	characterHolder * charHolder = new characterHolder;
	int count = 1;
	cout << "Please enter lines of text to test for correct delimitation.\n";
	do {
		getline(cin, currentLine, '\n');	//takes user input
		for (unsigned int i = 0; i < currentLine.length(); i++) {
			if (currentLine.at(i) == '(' || currentLine.at(i) == '[' || currentLine.at(i) == '{') { //checks each character for delimiters and if found pushes to stack
				stack->push(currentLine.at(i), count, i);
			}

			delimiterCheck('}', i, count, currentLine, charHolder, stack);
			delimiterCheck(']', i, count, currentLine, charHolder, stack);
			delimiterCheck(')', i, count, currentLine, charHolder, stack);

		}
		count++;
	} while (currentLine != "DONE");

	while (!stack->isEmpty()) {	//empties stack if not empty
			stack->popDelimiter(charHolder->character, charHolder->line, charHolder->characterNum);
			printf("Left delimiter %c at line %d, char %d had no right delimiter.\n", charHolder->character, charHolder->line, charHolder->characterNum);
		}

	return 0;
}

void delimiterCheck(char testChar, int increment, int count, string testString, characterHolder* holder, DelimiterStack* stack) {	//checks to see if right delimiter (testChar) matches the delimiter popped off the stack
	if (testString.at(increment) == testChar) {
		if (stack->isEmpty()) {
			printf("Right delimiter %c had no left delimiter found at line %d, char %d\n", testString.at(increment), count, increment + 1);
			holder->character = '\0';	//set to null so that erroneous error messages wouldn't occur
		}
		stack->popDelimiter(holder->character, holder->line, holder->characterNum);
		if (holder->character != matchingDelimiter(testChar) && holder->character != '\0'){
			printf("Mismatched delimiter %c found at line %d, character %d does not match %c found at line %d, character %d\n", holder->character, holder->line, holder->characterNum, testString.at(increment), count, increment + 1);
		}
	}
}

char matchingDelimiter (char character) {	//returns the matching left delimiter for right input delimiter (character)
	if (character == ')') {
		return '(';
	} else 	if (character == '}') {
		return '{';
	} else 	if (character == ']') {
		return '[';
	} else return '\0';
}
