/*
* @Author
* Student Name: Pelin Hakverir
* Student ID : 150140031
* Date: 21.12.2015
*/

//this cpp file is created to store the stack functions

#include "TemporaryPlace.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstring>

using namespace std;

void Stack::create(){
	head = NULL;
}

void Stack::close(){
	TempCardPlace *traverse;
	while (head) {
		traverse = head;
		head = head->next;
		delete traverse->card;
		delete traverse;
	}
}

void Stack::push(CardFeatures *newCard){
	TempCardPlace *Card = new TempCardPlace;
	Card->card = newCard;
	Card->next = head;
	head = Card;
}

CardFeatures* Stack::pop(){
	TempCardPlace *TopCard;
	CardFeatures *temp;
	TopCard = head;
	head = head->next;
	temp = TopCard->card;
	delete TopCard;
	return temp;
}

bool Stack::isempty(){
	return head == NULL;
}
