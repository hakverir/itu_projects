#ifndef INSTRUCTORLIST_H
#define INSTRUCTORLIST_H

#include "Instructor.h"

class InstructorList{
	Instructor *teachers;
	int size=3;
public:
	InstructorList();
	InstructorList(int);
	void add(char * , char * , char * , int , int , char * , char * , char * []);
	void deleteIns(char *, char *);
	void list() const;
	bool SearchByNames(char *) const;
	bool SearchByNumbers(int) const;
	int getsize(){
		return size;
	}
	~InstructorList();
};

#include <iostream>
#include <cstring>
using namespace std;

InstructorList::InstructorList(){
	teachers[size];
}

InstructorList::InstructorList(int Size){
	size = Size;
	teachers[size];
}

void InstructorList::add(char * title, char * name, char * surname, int tel, int room, char * user, char * mail, char * course[]){
	int i = 0;
	for (; i < size; i++){
		if (strcmp(teachers[i].getInformationChar("name"), " ") == 0)
			break;
	}
	if (i<size)
		teachers[i].setInformation(title, name, surname, tel, room, user, mail, course);
	else{
		Instructor *backup;
		backup = new Instructor[size++];
		for (int i = 0; i < size; i++)
			backup[i] = teachers[i];
		delete[] teachers;
		teachers = new Instructor[size];
		for (int i = 0; i < size; i++)
			teachers[i] = backup[i];
		delete[] backup;
		teachers[size].setInformation(title, name, surname, tel, room, user, mail, course);
	}

}

void InstructorList::deleteIns(char *name, char *surname){
	for (int i = 0; i < size; i++){
		if (strcmp(name, teachers[i].getInformationChar("name")) == 0){
			if (strcmp(surname, teachers[i].getInformationChar("surname")) == 0){
				if (size >= 1){
					for (; i < size - 1; i++)
						teachers[i] = teachers[i + 1];
				}
				else if (size == 1)
					teachers[i].setInformation(" ", " ", " ", 0, 0, " ", " ", NULL);
			}
		}
	}
}

InstructorList::~InstructorList(){
	delete[] teachers;
}

void InstructorList::list() const{
	for (int i = 0; i < size ; i++)
		teachers[i].print();
}

bool InstructorList::SearchByNames(char * name) const{
	bool flag = false;
	for (int i = 0; i < size; i++){
		if (strcmp(name, teachers[i].getInformationChar("name")) == 0){
			teachers[i].print();
			flag = true;
		}
	}

	if (flag == true) return flag;

	for (int i = 0; i < size; i++){
		if (strcmp(name, teachers[i].getInformationChar("surname")) == 0){
			teachers[i].print();
			flag = true;
		}
	}

	return flag;
}

bool InstructorList::SearchByNumbers(int number) const{
	bool flag = false;
	for (int i = 0; i < size; i++){
		if (number == teachers[i].getInformationInt("tel")){
			teachers[i].print();
			flag = true;
		}
	}

	if (flag == true) return flag;

	for (int i = 0; i < size; i++){
		if (number == teachers[i].getInformationInt("room")){
			teachers[i].print();
			flag = true;
		}
	}

	return flag;
}

#endif