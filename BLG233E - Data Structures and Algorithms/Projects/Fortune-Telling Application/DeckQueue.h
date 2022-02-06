/*
* @Author
* Student Name: Pelin Hakverir
* Student ID : 150140031
* Date: 21.12.2015
*/

#ifndef DECKQUEUE_H
#define DECKQUEUE_H
#include "MainStructs.h"

struct DeckCards{ //this struct is used to store the cards of the deck in shuffled order
	CardFeatures *card;
	DeckCards *next;
};

struct Queue{ //this struct is used to store the queue functions
	DeckCards *front;
	DeckCards *back;
	void create();
	void close();
	void enqueue(CardFeatures*);
	CardFeatures* dequeue();
	bool isempty();
};

#endif