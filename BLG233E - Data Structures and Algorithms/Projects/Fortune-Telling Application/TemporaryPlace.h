/*
* @Author
* Student Name: Pelin Hakverir
* Student ID : 150140031
* Date: 21.12.2015
*/

#ifndef TEMPORARYPLACE_H
#define TEMPORARYPLACE_H

#include "DeckQueue.h"
#include "MainStructs.h"

struct TempCardPlace{ //this struct is used to store the cards which does not match
	CardFeatures *card;
	TempCardPlace *next;
};

struct Stack{ //this struct is used to store the stack functions
	TempCardPlace *head;
	void create();
	void close();
	void push(CardFeatures *);
	CardFeatures* pop();
	bool isempty();
};







#endif