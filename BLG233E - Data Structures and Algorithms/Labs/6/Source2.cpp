#include <iostream>
#include <cstdio>
#include "Header.h"

using namespace std;

void StackOP::create(){
	head = NULL;
}

void StackOP::close(){
	Stack *p;
	while (head){
		p = head;
		head = head->next;
		delete p;
	}
}

void StackOP::push(char thechar){
	Stack *newnode = new Stack;
	newnode->ch = thechar;
	topStack = thechar;
	newnode->next = head;
	head = newnode;
}

char StackOP::pop(){
		Stack *newnode = new Stack;
		char thechar;
		newnode = head;
		thechar = newnode->ch;
		head = head->next;
		delete newnode;
		return thechar;
}

bool StackOP::isempty(){
	return head == NULL;
}
