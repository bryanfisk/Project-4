#ifndef DELIMITERSTACK_H_
#define DELIMITERSTACK_H_

class DelimiterStack {
	private:
	struct DelimiterNode { //struct for storing delimiter character information on the stack
	  char character;
	  int lineNumber;
	  int charCount;
	};
	DelimiterNode * stackPtr;
	int top;
	int size;
	public:
	DelimiterStack (int);
	void push(char, int, int);
	void popDelimiter(char&, int &, int &); // reference variables because three variables cannot be returned through return statement
	bool isEmpty() const;
	bool isFull() const;
	~DelimiterStack();
};

#endif /* DELIMITERSTACK_H_ */
