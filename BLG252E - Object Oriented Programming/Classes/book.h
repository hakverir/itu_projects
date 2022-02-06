/*
* @Author
* Student Name: Pelin Hakverir
* Student ID : 150140031
* Date: 08/04/2016
*/
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Book{
private:
	string label;
	double weight;
	double length;
	double width;
	double totalWeight;
public:
	Book();
	Book(string, double, double, double);
	string getLabel() { return label; }
	double getWeight() { return weight; }
	double getLength() { return length; }
	double getWidth() { return width; }
	double getTotal() { return totalWeight; }
	char getType(){ return 'B'; }
    void printByType() { cout << "Box<Book>"; }
    friend std::ostream &operator << (std::ostream &element, const Book &newElement){
        element << "Book Label: "<<newElement.label<<" # "<< newElement.length<<"x"<<newElement.width<<" "<<newElement.weight<<"kg "<<endl;
        return element;
    }
	~Book(){}
};

#endif

