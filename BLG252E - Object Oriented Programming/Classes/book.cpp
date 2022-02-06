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

Book::Book(){
	label = " ";
	weight = 0;
	length = 0;
	width = 0;
}

Book::Book(string BookLabel, double BookWeight, double BookLength, double BookWidth){
	label = BookLabel;
	weight = BookWeight;
	length = BookLength;
	width = BookWidth;
	totalWeight = weight;
}

