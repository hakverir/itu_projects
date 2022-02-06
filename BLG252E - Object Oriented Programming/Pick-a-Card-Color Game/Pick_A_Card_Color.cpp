//Pelin Hakverir
//150140031

#include <iostream>
#include <fstream>
#include <vector>

#include "Cards.h"
#include "List.h"

using namespace std;

void displayResults(int lose_1, int tie_1, int win_1, vector<int> &Score1, vector<int> &Score2){
    cout << "Score 1: ";
	for (int k = 0; k < 10; k++) std::cout << Score1[k] << " ";
    cout << endl;

    cout << "Score 2: ";
	for (int k = 0; k < 10; k++) std::cout << Score2[k] << " ";
    cout << endl;

    cout << "Total Score1 : Lose : " << lose_1 << " Tie : " << tie_1 << " Win : " << win_1 << endl;
    cout << "Total Score2 : Lose : " << win_1 << " Tie : " << tie_1 << " Win : " << lose_1 << endl;

	if (win_1 > lose_1)
        cout << "Winner : Player1" << endl;
	else if (win_1 < lose_1)
        cout << "Winner : Player2" << endl;
	else
        cout << "Tie!" << endl;
}

int main(){
	char cardColor;
	ifstream Deck;
	Deck.open("deck.txt");

    HetList Player1;
    HetList Player2;

	char color2;

	bool flag = false;
	int counter = 0;

	int lose = 0;
	int win = 0;
	int tie = 0;

	vector<int> score1;
	vector<int> score2;


    Red r;
    Blue b;
    Green g;
    DarkRed d;

	while (!Deck.eof()){									//till the end of file
		cardColor = Deck.get();								//get a card color
        if (cardColor == ' ' || cardColor == -1) continue;						//if blank, skip
		else if (cardColor == '\n') continue;				//if blank, skip
		else{												//if a color
			counter++;										//count that this is a card
			switch (cardColor){								//find the right case
			case 'R':								//create a red card class
                if (flag == false) Player1.Insert(r);		//insert the red card into the list
                else Player2.Insert(r);
				break;
			case 'G':								//create a green card class
                if (flag == false) Player1.Insert(g);		//insert the green card into the list
                else Player2.Insert(g);
				break;
			case 'B':
                if (flag == false) Player1.Insert(b);		//insert the blue card into the list
                else Player2.Insert(b);
				break;
			case 'D':
                if (flag == false) Player1.Insert(d);		//insert the dark red card into the list
                else Player2.Insert(d);
				break;
			default:										//nothing to do if card color is not valid
				std::cout << "Something just happened. A card color is not valid. It is in the line for the ";
				if (flag == false) std::cout << "Player 1 ";
				else std::cout << "Player 2 ";
				std::cout << "and it is the " << counter << ". card of this player.";
				break;
			}
			if (counter == 10) flag = true;
		}
	}
    unsigned long i = 0;

    ListNode *temp1 = Player1.getHead ();
    ListNode *temp2 = Player2.getHead ();

    while (temp1 && temp2 && i<11){
            color2 = temp2 -> card -> getColor ();
            if (temp1 -> card -> compare(color2) == 0){
				lose++;
                score1.push_back (0);
                score2.push_back (2);
			}
            else if (temp1 -> card -> compare(color2) == 1){
				tie++;
                score1.push_back (1);
                score2.push_back (1);
			}
            else if (temp1 -> card -> compare(color2) == 2){
				win++;
                score1.push_back (2);
                score2.push_back (0);
			}
            if(temp1->GetNext ())
                temp1 = temp1->GetNext ();
            if(temp2->GetNext ())
                temp2 = temp2->GetNext ();
			i++;
	}
    delete temp1;
    delete temp2;
    ListNode *tmp1 = Player1.getHead ();
    ListNode *tmp2 = Player2.getHead ();
   cout << "Player 1: ";
   int x=10;
    while (x--){
        cout << temp1 -> card -> getColor() << " ";
            tmp1 = tmp1->GetNext ();
    }
	cout << endl;
    cout << "Player 2: ";
    x=10;

    while (x--){
        cout << temp1 -> card -> getColor() << " ";
            tmp2=tmp2->GetNext ();
    }
    cout << endl;

	displayResults(lose, tie, win, score1, score2);

	Deck.close();
}
