#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

class Instructor{
	friend class InstructorList;

	char *Title = new char[10];
	char *FirstName = new char[20];
	char *LastName = new char[20];
	int TelephoneNum;
	int RoomNum;
	char *UserName = new char[20];
	char *Email = new char[30];
	char **courses = new char*[5];

public:
	Instructor();
	Instructor(char *, char *, char *, int, int, char *, char *, char *[]);
	char * getInformationChar(char *) const;
	int getInformationInt(char *) const;
	void setInformation(char *, char *, char *, int, int, char *, char *, char *[]);
	void print() const;
	~Instructor();
};

#include <iostream>
#include <cstring>
using namespace std;

Instructor::Instructor(){
	strcpy(Title, " ");
	strcpy(FirstName, " ");
	strcpy(LastName, " ");
	TelephoneNum = 0;
	RoomNum = 0;
	strcpy(UserName, " ");
	strcpy(Email, " ");
	strcpy(courses[0], " ");
}

Instructor::Instructor(char * title, char * name, char * surname, int tel, int room, char * user, char * mail, char * course[]){
	strcpy(Title, title);
	strcpy(FirstName, name);
	strcpy(LastName, surname);
	TelephoneNum = tel;
	RoomNum = room;
	strcpy(UserName, user);
	strcpy(Email, mail);
	strcpy(courses[0], course[0]);
	for (int i = 1; i < 10; i++){
		if (strcmp(course[i], " ") !=0)
			strcpy(courses[i], course[i]);
	}
}

void Instructor::print() const{
	cout << "Title: " << Title << endl;
	cout << "First Name: " << FirstName << endl;
	cout << "Surname: " << LastName << endl;
	cout << "Telephone Number: " << TelephoneNum << endl;
	cout << "Room Number: " << RoomNum << endl;
	cout << "User Name: " << UserName << endl;
	cout << "Email: " << Email << endl;
	cout << "Courses: [ " << courses[0];
	for (int i = 1; i < 10; i++){
		if (strcmp(courses[i], " ") != 0)
			cout << ", " << courses[i];
	}
	cout << "]" << endl;
}

char * Instructor::getInformationChar(char *wanted) const{
	if (strcmp(wanted, "name")==0)
		return FirstName;
	else if (strcmp(wanted, "surname") == 0)
		return LastName;
	else
		return 0;
}

int Instructor::getInformationInt(char * wanted) const{
	if (strcmp(wanted, "tel")==0)
		return TelephoneNum;
	else if (strcmp(wanted, "room") == 0)
		return RoomNum;
	else
		return 0;
}

void Instructor::setInformation(char * title, char * name, char * surname, int tel, int room, char * user, char * mail, char * course[]){
	//if (strcmp(title, " ")!=0)
		strcpy(Title, title);
	//if (strcmp(name, " ") != 0)
		strcpy(FirstName, name);
	//if (strcmp(surname, " ") != 0)
		strcpy(LastName, surname);
	//if (tel != 0)
		TelephoneNum = tel;
	//if (room != 0)
		RoomNum = room;
	//if (strcmp(user, " ") != 0)
		strcpy(UserName, user);
	//if (strcmp(mail, " ") != 0)
		strcpy(Email, mail);
	for (int i = 0; i < 10; i++){
		//if (strcmp(courses[i], " ") != 0)
			strcpy(courses[i], course[i]);
	}
}

Instructor::~Instructor(){
	delete Title;
	delete FirstName;
	delete LastName;
	delete UserName;
	delete Email;
	delete [] courses;
}

#endif