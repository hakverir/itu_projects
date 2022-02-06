//Pelin Hakverir
//150140031

#ifndef CARDS_H
#define CARDS_H

#include <iostream>

class Cards{						//base abstract class
protected:
	enum result{ Lose = 0, Tie = 1, Win = 2 };
	char color;
public:
	Cards();
    virtual int compare(char) = 0;
	virtual char getColor();
	void setColor(char Color){ color = Color; }
	~Cards(){}
};

Cards::Cards(){ 
    color = 'A';
}

class Green: public Cards{
	char color;
public:
	Green() :color('G'){ setColor(color); }
	int compare(char);
	char getColor(){ return color; }
	~Green(){}
};

int Green::compare(char Opponent){
	if (Opponent == 'B')
		return 2;
	else if (Opponent == 'D')
		return 2;
	else if (Opponent == 'R')
		return 0;
	else if (Opponent == 'G')
		return 1;
	else return -1;
}


class Blue: public Cards{
	char color;
public:
	Blue() :color('B'){ setColor(color); }
	int compare(char);
	char getColor(){ return color; }
	~Blue(){}
};

int Blue::compare(char Opponent){
	if (Opponent == 'R')
		return 2;
	else if (Opponent == 'D')
		return 0;
	else if (Opponent == 'G')
		return 0;
	else if (Opponent == 'B')
		return 1;
	else
		return -1;
}


class Red: public Cards{
	char color;
public:
	Red() :color('R'){ setColor(color); }
	int compare(char);
	char getColor(){ return color; }
	~Red(){}
};

int Red::compare(char Opponent){
	if (Opponent == 'G')
		return 2;
	else if (Opponent == 'D')
		return 0;
	else if (Opponent == 'B')
		return 0;
	else if (Opponent == 'R')
		return 1;
	else return -1;
}


class DarkRed: public Red{
	char color;
public:
	DarkRed() :color('D'){}
	int compare(char);
	char getColor(){ return color; }
	~DarkRed(){}
};

int DarkRed::compare(char Opponent){
	if (Opponent == 'B')
		return 2;
	else if (Opponent == 'R')
		return 2;
	else if (Opponent == 'G')
		return 0;
	else if (Opponent == 'D')
		return 1;
	else return -1;
}

#endif
