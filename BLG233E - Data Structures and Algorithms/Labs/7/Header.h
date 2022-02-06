#ifndef HEADER_H
#define HEADER_H

struct lab{
	char x;
	char y;
	int up;
	int down;
	int right;
	int left;
	char prev;
	lab *next;
	char criticalpoint[1][2];
};

struct StackOP{
	lab *head;
	void create();
	void close();
	void push(char);
	char pop();
};


#endif