#include <iostream>
#include <cstdio>
#include "Header.h"

using namespace std;

void StackOP::create(){
	head = NULL;
}

void StackOP::close(){
	lab *p;
	while (head){
		p = head;
		head = head->next;
		delete p;
	}
}