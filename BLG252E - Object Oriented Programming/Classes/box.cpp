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

template <class MyBox>
Box<MyBox>::Box(double BoxWeight, double BoxLength, double BoxWidth, double BoxMax){
	label = "Box";
	weight = BoxWeight;
	length = BoxLength;
	width = BoxWidth;
	maxWeight = BoxMax;
	totalWeight = weight;
	STACKSIZE = 3;
	MyStack = NULL;
	current = 0;
    ERROR1= "Index out of bounds!";
	ERROR2 = "The dimensions of the contained object should be equal or smaller than those of the box!";
	ERROR3 = "The total weight of the contained objects including the box may not exceed the maximum allowed weight for the box!";
}

template <class MyBox>
Box<MyBox>::Box(){
	STACKSIZE = 3;
	MyStack = NULL;
	current = 0;
	ERROR1 = "Index out of bounds!";
	ERROR2 = "The dimensions of the contained object should be equal or smaller than those of the box!";
	ERROR3 = "The total weight of the contained objects including the box may not exceed the maximum allowed weight for the box!";
}


template <class MyBox>
Box<MyBox>::Box(Box<MyBox> &newBox){
    MyStack =  new MyBox[newBox.STACKSIZE];
    label = newBox.label;
    weight = newBox.weight;
    length = newBox.length;
    width = newBox.width;
    maxWeight = newBox.maxWeight;
    totalWeight = newBox.totalWeight;
    STACKSIZE = newBox.STACKSIZE;
    for (int i = 0; i < newBox.STACKSIZE; i++)
		MyStack[i] = newBox.MyStack[i];
    current = newBox.current;
	ERROR1 = "Index out of bounds!";
	ERROR2 = "The dimensions of the contained object should be equal or smaller than those of the box!";
	ERROR3 = "The total weight of the contained objects including the box may not exceed the maximum allowed weight for the box!";
}

template <class MyBox>
void Box<MyBox>::add(MyBox &temp){
	if (MyStack == NULL){
            if (temp.getTotal() <= (maxWeight-totalWeight) && ((temp.getLength() <= length && temp.getWidth() <= width) || (temp.getWidth() <= length && temp.getLength() <= width))){
				MyStack = new MyBox[STACKSIZE];
				MyStack[0] = temp;
                totalWeight += temp.getTotal();
				current++;
			}
			else if (temp.getTotal() > (maxWeight - totalWeight)) throw ERROR3;
			else throw ERROR2;
	}

	else if (MyStack != NULL && current < STACKSIZE){
            if (temp.getTotal() <= (maxWeight-totalWeight) && ((temp.getLength() <= length && temp.getWidth() <= width) || (temp.getWidth() <= length && temp.getLength() <= width))){
			MyStack[current] = temp;
			totalWeight += temp.getTotal();
			current++;
			}
			else if (temp.getTotal() > (maxWeight - totalWeight)) throw ERROR3;
			else throw ERROR2;
	}

    else if (MyStack != NULL && current == STACKSIZE){
            if (temp.getTotal() <= (maxWeight-totalWeight) && ((temp.getLength() <= length && temp.getWidth() <= width) || (temp.getWidth() <= length && temp.getLength() <= width))){
			int i = 0;
			MyBox *tempStack = new MyBox[++STACKSIZE];
			for (; i < STACKSIZE - 1; i++)
                tempStack[i] = MyStack[i];
            tempStack[i] = temp;
			delete[] MyStack;
			MyBox *MyStack = new MyBox[++STACKSIZE];
			for (; i < STACKSIZE - 1; i++)
				MyStack[i] = tempStack[i];
			totalWeight += temp.getTotal();
			current++;
			delete[] tempStack;
			}
			else if (temp.getTotal() > (maxWeight - totalWeight)) throw ERROR3;
			else throw ERROR2;
	}
}

template <class MyBox>
void Box<MyBox>::add(MyBox *temp, int size){
    if (MyStack == NULL){
            STACKSIZE = size;
			MyStack = new MyBox[STACKSIZE];
			for (int k = 0; k < size; k++){
                if (temp[k].getTotal() <= (maxWeight-totalWeight) && ((temp[k].getLength() <= length && temp[k].getWidth() <= width) || (temp[k].getWidth() <= length && temp[k].getLength() <= width))){
					MyStack[k] = temp[k];
					totalWeight += temp[k].getTotal();
					current++;
				}
				else if (temp[k].getTotal() > (maxWeight - totalWeight)) throw ERROR3;
				else throw ERROR2;
			}
	}

    else if (MyStack != NULL && (STACKSIZE-current)>=size){
			for (int k = 0; k < size; k++){
                if (temp[k].getTotal() <= (maxWeight-totalWeight) && ((temp[k].getLength() <= length && temp[k].getWidth() <= width) || (temp[k].getWidth() <= length && temp[k].getLength() <= width))){
				MyStack[current++] = temp[k];
				totalWeight += temp[k].getTotal();
				}
				else if (temp[k].getTotal() > (maxWeight - totalWeight)) throw ERROR3;
				else throw ERROR2;
			}
	}

    else if (MyStack != NULL && (current == STACKSIZE || (STACKSIZE-current)<size)){
            int tempSize = STACKSIZE+size+1;
			int m = 0;
			MyBox *tempStack = new MyBox[STACKSIZE];
            for (int i=0; i < STACKSIZE; i++)
				tempStack[i] = MyStack[i];
            delete[] MyStack; //i=STACKSIZE
            MyBox *MyStack = new MyBox[tempSize];
            for (; m < STACKSIZE; m++)
                MyStack[m] = tempStack[m];
			m -= (STACKSIZE - current);
            STACKSIZE=tempSize;
            delete[] tempStack;

			for (int k = m, j = 0; size!=0 ; k++, j++, size--){
                if (temp[j].getTotal() <= (maxWeight-totalWeight) && ((temp[j].getLength() <= length && temp[j].getWidth() <= width) || (temp[j].getWidth() <= length && temp[j].getLength() <= width))){
                MyStack[k] = temp[j];
                totalWeight += temp[j].getTotal();
                current++;
				}
				else if (temp[k].getTotal() > (maxWeight - totalWeight)) throw ERROR3;
				else throw ERROR2;
            }
	}
}

template<class T>
void Box<T>::printByType() const
{
	cout << "Box<";
	MyStack->printByType();
	cout << ">";
}

template <class MyBox>
Box<MyBox>::~Box(){
    //delete[] MyStack;
}

