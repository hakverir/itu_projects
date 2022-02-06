/*
* @Author
* Student Name: Pelin Hakverir
* Student ID : 150140031
* Date: 21.12.2015
*/

#include "DeckQueue.h"
#include "TemporaryPlace.h"
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

Queue Deck;
Queue SpecialPlace;
Stack TempPlace;
CardFeatures NewDeck[4][13];

char type[4] = { 'H' , 'D', 'S', 'C' };
char *number[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
int values[13] = { 10, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

int counter = 0;
int counter4 = 0;
int counter13 = 0;

void shuffle(CardFeatures [][13]);
void createDeck();

int main(){
	srand(time(NULL));
	CreateDeck *Card=new CreateDeck;
	DeckCards *traverse = new DeckCards;
	Card->card = new CardFeatures;
	Deck.create();
	SpecialPlace.create();
	TempPlace.create();
	createDeck();

	int sum = 0;
	int CardNum = 0;
	char *cardCounter[13];
	for (int i = 0; i < 13; i++)
		cardCounter[i]= number[i];

	cout << "Make a wish!" << endl;

	if (!(freopen("output.txt", "w+", stdout))){ //to write outputs on the file
		cout << "File could not be opened (output)\n" << endl;
	}

	cout << "Shuffled deck:" << endl;
	shuffle(NewDeck);
	counter = 1;
	//to write the shuffle result, aka queue
	Deck.back->next = NULL;
	traverse = Deck.front;
	while (traverse){
		cout << counter << ":" << traverse->card->cardType << ":" << traverse->card->cardNumber << endl;
		traverse = traverse->next;
		counter++;
	}
		
	cout << "Fortune telling steps: " << endl;

	while (!Deck.isempty()){//until all of the cards in the queue(deck) are checked
		Card->card = Deck.dequeue();//take a card
		CardNum++;
		cout << CardNum << ":" << Card->card->cardType << ":" << Card->card->cardNumber << ":";

		if (Card->card->cardNumber == cardCounter[CardNum-1]){//if it matches
			SpecialPlace.enqueue(Card->card); //store in a queue
			while (!TempPlace.isempty()) //if there were unmatched cards
				Deck.enqueue(TempPlace.pop()); //add them at the end of the queue
			CardNum = 0;
			cout << "match" << endl;
			continue;
		}

		else{ //if does not match
			TempPlace.push(Card->card); //push it into the stack(temporary place)
			cout << "unmatch" << endl;
		}
			

		if (CardNum == 13|| (CardNum<13 && Deck.isempty())){ //if any of the cards in a 13 pack does not match
			while (!TempPlace.isempty())
				TempPlace.pop();
			CardNum = 0;
		}
	}

	cout << "Fortune results:" << endl;

	while (!SpecialPlace.isempty()){ //until the store queue is empty
		Card->card = SpecialPlace.dequeue(); //take a card
		cout << Card->card->cardType << ":" << Card->card->cardNumber << endl;
		sum += Card->card->cardValue; //add them
	}

	cout << "Sum: " << sum << endl;

	if (sum < 50)
		cout << "Bad luck!" << endl;
	else
		cout << "Fortune will come true!" << endl;

	Deck.close();
	SpecialPlace.close();
	TempPlace.close();
	return 0;
}

void shuffle(CardFeatures DeckCard[][13]){
	if (counter < 52){ //I used 52 for storage, it has no effect on swap part (it has about swapping numbers, but it won't be a problem for this part if it was 40 or 60)
		swap(DeckCard[rand() % 4][rand() % 13], DeckCard[rand() % 4][rand() % 13]); //swap random cards
		counter++;
		shuffle(DeckCard); //shuffle other cards
	}
	if (counter13 == 13 && counter!=0){ //if a part is passed
		counter4++; //pass to another type
		counter13 = 0; //come to the beginning of the new type
	}
	if (counter13 < 13 && counter!=0){ //if the type hasn't ended
		Deck.enqueue(DeckCard[counter4] + counter13); //store it in the deck queue
		counter13++;
	}
	counter--;
}

void createDeck(){
	for (int i = 0; i < 4; i++){ //for the type
		for (int j = 0; j < 13; j++){ //for the numbers
			NewDeck[i][j].cardNumber = number[j];
			NewDeck[i][j].cardType = type[i];
			NewDeck[i][j].cardValue = values[j];
		}
	}
}
