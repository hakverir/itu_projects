/*
* @Author
* Student Name: Pelin Hakverir
* Student ID : 150140031
* Date: 21.12.2015
*/

#ifndef MAINSTRUCTS_H
#define MAINSTRUCTS_H

struct CardFeatures{ //this is the main struct. it contains the features of the cards. the first deck is stored with an array of this struct
	char *cardNumber;
	char cardType;
	int cardValue;
};

struct CreateDeck{ //this struct is created to be used in the main function while controlling the cards if they match
	CardFeatures *card;
	CreateDeck *next;
};

#endif