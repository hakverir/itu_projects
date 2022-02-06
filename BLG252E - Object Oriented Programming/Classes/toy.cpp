/*
* @Author
* Student Name: Pelin Hakverir
* Student ID : 150140031
* Date: 08/04/2016
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "box.h"
#include "book.h"
#include "toy.h"
using namespace std;

Toy::Toy(){
	label = " ";
	weight = 0;
	length = 0;
	width = 0;
	flag = false;
}

Toy::Toy(string ToyLabel, double ToyWeight, double ToyLength, double ToyWidth, bool Battery){
	label = ToyLabel;
	weight = ToyWeight;
	length = ToyLength;
	width = ToyWidth;
	flag = Battery;
	totalWeight = weight;
}

