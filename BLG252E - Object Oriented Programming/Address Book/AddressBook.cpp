#include "InstructorList.h"
#include <iostream>

using namespace std;

int main(){
	int choice = 0;
	InstructorList instructors;
	char *newTitle = new char[10];
	char *newName = new char [20];
	char *newSurname = new char [20];
	int newPhone = 0;
	int newRoom = 0;
	char *newUser = new char [20];
	char *newMail = new char[30];
	char *newCourse = new char[7];
	char **newCourses = new char* [5];
	char option;

	do{
		cout << "1. Add a new instructor" << endl;
		cout << "2. Delete an instructor" << endl;
		cout << "3. List all instructors" << endl;
		cout << "4. Search by Name" << endl;
		cout << "5. Search by Surname" << endl;
		cout << "6. Search by Telephone Number" << endl;
		cout << "7. Search by Room Number" << endl;
		cout << "8. Exit" << endl;
		cout << "Enter the number for operation you want to perform :" << endl;

		cin >> choice;
		switch (choice){
		case 1:
			cout << "Enter the title: " << endl;
			cin.getline(newTitle, 1000);
			cout << "Enter the First Name: " << endl;
			cin.getline(newName, 1000);
			cout << "Enter the Last Name: " << endl;
			cin.getline(newSurname, 1000);
			cout << "Enter the Telephone Number: " << endl;
			cin >> newPhone;
			cout << "Enter the Room Number: " << endl;
			cin >> newRoom;
			cout << "Enter the User Name: " << endl;
			cin.getline(newUser, 1000);
			cout << "Enter the Email: " << endl;
			cin.getline(newMail, 1000);
			cout << "Enter the courses: " << endl;
			cin.getline(newCourse, 1000);
			char course[7];
			for (int i=0;newCourse[i]!='\0'; i++){
				for (int j = 0; newCourse[i] != ','; j++){
					course[j] = newCourse[i];
				}
				newCourses[i] = course;
				course[0] = '\0';
			}

			instructors.add(newTitle, newName, newSurname, newPhone, newRoom, newUser, newMail, newCourses);
			cout << "New instructor is added!" << endl;
			break;
		case 2:
			if (instructors.getsize() == 0){
				cout << "It is not possible to delete while no one is added!" << endl;
			}
			else{
				cout << "Enter the first name of the record to be deleted:" << endl;
				cin.getline(newName, 1000);
				cout << "Enter the last name of the record to be deleted:" << endl;
				cin.getline(newSurname, 1000);
				instructors.deleteIns(newName, newSurname);
			}
			break;
		case 3:
			cout << "----------List of all Instructors in Computer Engineering of ITU----------" << endl << endl;
			instructors.list();
			break;
		case 4:
			cout << "----------Search Results----------" << endl;
			cout << "Enter the first name: " << endl;
			cin.getline(newName, 1000);
			instructors.SearchByNames(newName);
			break;
		case 5:
			cout << "----------Search Results----------" << endl;
			cout << "Enter the last name: " << endl;
			cin.getline(newSurname, 1000);
			instructors.SearchByNames(newSurname);
			break;
		case 6:
			cout << "----------Search Results----------" << endl;
			cout << "Enter the telephone number: " << endl;
			cin >> newPhone;
			instructors.SearchByNumbers(newPhone);
			break;
		case 7:
			cout << "----------Search Results----------" << endl;
			cout << "Enter the room number: " << endl;
			cin >> newRoom;
			instructors.SearchByNumbers(newRoom);
			break;
		case 8:
			option = 'E';
			break;
		default:
			cout << "Please try again" << endl;
			option = 'Y';
			break;
		}
		if (option != 'Y' || option !='E'){
			cout << "Do you want to perform another operation ? (Y / N)" << endl;
			cin >> option;
		}
	}

	while (option == 'Y' || option == 'y');
}