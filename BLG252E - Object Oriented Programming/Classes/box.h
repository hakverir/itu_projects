/*
* @Author
* Student Name: Pelin Hakverir
* Student ID : 150140031
* Date: 08/04/2016
*/
#ifndef BOX_H
#define BOX_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

template <class MyBox>
class Box{
private:
	int STACKSIZE;
	MyBox *MyStack;
    string label;
	double weight;
	double length;
	double width;
	double maxWeight;
	double totalWeight;
	int current;
    string ERROR1;
	string ERROR2;
	string ERROR3;
public:
	Box(double, double, double, double);
	Box();
	Box(Box<MyBox> &);
    void add(MyBox&);
	void add(MyBox*, int);
	MyBox pop();
	string getLabel() { return label; }
	double getWeight() { return weight; }
	double getLength() { return length; }
	double getWidth() { return width; }
	double getMax() { return maxWeight; }
	double getTotal() { return totalWeight; }
	int getCurrent() { return current; }
	int getSize() { return STACKSIZE; }
	bool isEmpty() { return (MyStack == NULL); }
    MyBox operator[](int wantedElement) const {
        if(wantedElement>=current || wantedElement<0) throw ERROR1;
        return MyStack[wantedElement];}
	char getType(){ return 'X'; }
    ~Box();
    void printByType() const;
    friend std::ostream &operator << (std::ostream &element,const Box<MyBox> &newElement){

        element<<"***** ";
        newElement.MyStack->printByType();
        element<<" *****"<<endl;
        element<<"Box item count:"<<newElement.current<<endl;
        element<<"Size: "<< newElement.length<<"x"<<newElement.width<<" Box Weight:"<<newElement.weight<<"kg Total/Maximum Allowed Weight:";
        element<<newElement.totalWeight<<"kg/"<<newElement.maxWeight<<"kg"<<endl;
        element<<"Items:"<<endl;
        for(int i=0;i<newElement.current;i++){
            cout<< i+1<<":"<<newElement[i];
        }
        element<<"********************"<<endl;
        return element;
    }
};

#endif

