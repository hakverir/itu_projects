/*
* @Author
* Student Name: Pelin Hakverir
* Student ID : 150140031
* Date: 21.12.2015
*/

//this cpp file is created to store the queue functions

#include <iostream>
#include "DeckQueue.h"

using namespace std;

void Queue::create(){
	front = NULL;
	back = NULL;
}

void Queue::close(){
	DeckCards *traverse;
	while (front) {
		traverse = front;
		front = front->next;
		delete traverse->card;
		delete traverse;
	}
}

void Queue::enqueue(CardFeatures *newCard){
	DeckCards *Card = new DeckCards;
	Card->card = newCard;
	Card->next = NULL;
	if (isempty()){
		back = Card;
		front = back;
	}
	else{
		back->next = Card;
		back = Card;
	}
}

CardFeatures* Queue::dequeue() {
	DeckCards *TopCard;
	CardFeatures *temp;
	TopCard = front;
	front = front->next;
	temp = TopCard->card;
	delete TopCard;
	return temp;
}

bool Queue::isempty() {
	return front == NULL;
}
