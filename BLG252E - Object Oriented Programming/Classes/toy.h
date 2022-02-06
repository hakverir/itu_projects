/*
* @Author
* Student Name: Pelin Hakverir
* Student ID : 150140031
* Date: 08/04/2016
*/
#ifndef TOY_H
#define TOY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class Toy{
private:
	string label;
	double weight;
	double length;
	double width;
	double totalWeight;
	bool flag;
    char type;
public:
	Toy();
	Toy(string, double, double, double, bool);
	string getLabel() { return label; }
	double getWeight() { return weight; }
	double getLength() { return length; }
	double getWidth() { return width; }
	void setContainsBattery(bool isThereBattery){ flag = isThereBattery; }
	char getType(){ return 'T'; }
	bool getFlag(){ return flag; }
	double getTotal() { return totalWeight; }
    void printByType() const{ cout << "Box<Toy>"; }
    friend std::ostream &operator << (ostream &element, const Toy &newElement){

        element << "Toy Label: "<<newElement.label<<" # "<< newElement.length<<"x"<<newElement.width<<" "<<newElement.weight<<"kg ";
        if (newElement.flag==true) element<<"Contains Battery"<<endl;
        else element<<"No Battery"<<endl;

        return element;
    }
	~Toy(){}
};

#endif

