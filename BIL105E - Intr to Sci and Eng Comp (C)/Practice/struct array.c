#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card{
	const char *face;
	const char *suit;
};

typedef struct card Card;

void fillDeck(Card * const wDeck, const char *wFace[], const char *wSuit[]);
void shuffle (Card * const wDeck);
void deal(const Card * const wDeck);

int main(void){
	Card deck[52];
	const char *face[]={"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	const char *suit[]={"Hearts", "Diamonds", "Clubs", "Spades"};
	
	srand(time(NULL));
	
	fillDeck(deck,face,suit);
	shuffle(deck);
	deal(deck);
	
	return 0;
}

void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]){
	int i;
	for(i=0;i<=51;i++){
		wDeck[i].face=wFace[i%13];
		wDeck[i].suit=wSuit[i/13];
	}
}

void shuffle (Card * const wDeck){
	int i, j;
	Card temp;
	for(i=0;i<=51;i++){
		j=rand()%52;
		temp=wDeck[i]=wDeck[j];
		wDeck[j]=temp;
	}
}

void deal(const Card *const wDeck){
	int i;
	for(i=0;i<=51;i++){
		printf("%5s of %-8s\n", wDeck[i].face, wDeck[i].suit, (i+1)%4 ? " " : "\n");
	}
}
