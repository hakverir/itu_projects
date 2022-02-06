#ifndef HEADER_H
#define HEADER_H

struct Stack{
	char ch;
	Stack *next;
};

struct StackOP{
	Stack *head;
	void create();
	void close();
	void push(char);
	char pop();
	bool isempty();
	char topStack;
};


#endif