/* 
 * Student Name: Pelin Hakverir
 * Student ID : 150140031
 * Date:  13.10.2015
 */   
 
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>
#include "recordapps.h"
#include <stdio.h>

using namespace std;

//list of the function that I will use in the program
typedef thelist struct1;
struct1 record;
void read();
void write();
void menu();
bool operate(char);
void s_Writer();
void s_Type();
void add_record();
void update_record();
void delete_record();

int main(){
	record.create(); //creating the list from the beginning
	read(); //reading the file (if not exists, creates)
	bool end1 = false; //to determine when the user wants to end the program
	char choice; //user's choice
	while (!end1) {
		menu(); //writing the menu on screen
		cin >> choice; //taking the choice of the user
		end1 = operate(choice); //looking if the user wants to terminate or continue
	}
	write(); //writing and storing the new records to the file
return EXIT_SUCCESS;
}
	
void menu(){
	cout << endl << endl;
	cout << "Please select the operation to perform and enter the operation code" << endl;
	cout << "(P) Print the whole catalogue," << endl;
	cout << "(A) Search the catalogue by author," << endl;
	cout << "(T) Search the catalogue by book type," << endl;
	cout << "(I) Insert a new book record," << endl;
	cout << "(U) Update an existing book record," << endl;
	cout << "(R) Remove a book record," << endl;
	cout << "(E) Exit the program." << endl;
	cout << "Your selection is: " << endl;
	}
	
bool operate(char choice){ //taking the user's choice
	bool end2=false;
	switch (choice) {
		case 'P': case 'p':
			record.list();
			getchar();
			break;
		case 'A': case 'a': 
			s_Writer();
			break;
		case 'T': case 't': 
			s_Type();
			break;
		case 'I': case 'i':
			add_record();
			break;
		case 'U': case 'u':
			update_record();
			break;
		case 'R': case 'r':
			delete_record();
			break;
		case 'E': case 'e':
			cout << "Are you sure that you want to terminate the program? (Y/N):";
			cin >> choice;
			if(choice=='Y' || choice=='y') //if the user wants to terminate the program
				end2=true;
			break;
 		
		default: //if there was a wrong input
			cout << "Error: You have made an invalid choice" << endl;
			cout << "Try again {P, A, T, I, U, R, E} :" ;
			cin >> choice;
			end2 = operate(choice);
			break;
		}
	return end2;
}

void s_Type(){ //searching the records by the book type
	char typ[10];
	cout << "Please enter the name of the type you want to search (press '*' for listing all):" << endl;
	cin.ignore(1000, '\n');
	cin.getline(typ,10);
	if(record.sType(typ)==0){ //if there is no match
		cout << "Record can not be found" << endl;
	}
	getchar();
};

void s_Writer(){ //searching the records by the author's name
	char author[20];
	cout << "Please enter the name of the author you want to search (press '*' for listing all):" << endl;
	cin.ignore(1000, '\n');
	cin.getline(author,20);
	if(record.sWriter(author)==0){ //if there is no match
		cout << "Record can not be found" << endl;
	}
	getchar();
};

void add_record(){ //adding new book
	book_record newbook;
	cout << "Please enter the information of the book you want to save " << endl;
	
	cout << "Author Name : " ;
	cin.ignore(1000, '\n');
	cin.getline(newbook.authorName,20);
	
	cout << "Author Surname : " ;
	cin.getline(newbook.authorSurname,20);
	
	cout << "Title : " ;
	cin.getline(newbook.title,20);
	
	cout << "ISBN : ";
	cin >> setw(5) >> newbook.ISBN;
	
	cout << "Location : ";
	cin >> setw(4) >> newbook.location;
	
	cout << "Type : " ;
	cin.ignore(1000, '\n');
	cin.getline(newbook.bookType,20);
	
	record.add(&newbook); //sending the inputs to the background function
	
	cout << "Record has been added" << endl;
};

void delete_record(){ //deleting a book's informations/record
	int isbn;
	int choice;
	cout << "Please enter the ISBN of the book you want to remove (press '0' for listing all):" << endl;
	cin >> isbn;
	int kitapsayisi=record.sISBN(isbn); //searching if there are any matches found
	
	if(kitapsayisi==0){ //no match
		cout << "Record can not be found" << endl;
	}
	else {
		if (kitapsayisi==1){ //1 book
			cout << "Record has been found." << endl;
			cout << "Please enter the index of the record if you want to delete this book (Press -1 to exit without deletion): " ;
		}
		else //many books
			cout << "Please enter the index of the record that you want to delete (Press -1 to exit without deletion): " ;
			
		cin >> choice;
			if(choice==-1) return; //if user wants to cancel the process
				record.deletion(choice); //deleting if the choice is an index number
		cout << "Record has been deleted" <<endl;
	}
	getchar();
};

void update_record(){ //updating a record
	int isbn;
	int choice;
	cout << "Please enter the ISBN of the book you want to update (press '0' for listing all):" << endl;
	cin >> isbn;
	int kitapsayisi=record.sISBN(isbn); //searching if there are any matches found
	
	if(kitapsayisi==0){//no match
		cout << "Record can not be found" << endl;
	}
	else {
		if (kitapsayisi==1){// 1 match
			cout << "Record has been found." << endl;
			cout << "Please enter the index of the record if you want to update this book (Press -1 to exit without updating) " ;
		}
		else//many matches
			cout << "Please enter the index of the record that you want to update (Press -1 to exit without updating): " ;
		cin >> choice;
		if(choice==-1) return; //if user wants to cancel the process
		book_record newbook;
		cout << "Please enter the up-to-date information" << endl;
		
		cout << "Author Name : " ;
		cin.ignore(1000, '\n');
		cin.getline(newbook.authorName,20);

		cout << "Author Surname : " ;
		cin.getline(newbook.authorSurname,20);

		cout << "Title : " ;
		cin.getline(newbook.title,20);

		cout << "ISBN :";
		cin >> setw(5) >> newbook.ISBN;

		cout << "Location :";
		cin >> setw(4) >> newbook.location;
	
		cout << "Type : " ;
		cin.ignore(1000, '\n');
		cin.getline(newbook.bookType,20);
		
		record.update(choice,&newbook);//updating process with the background function
		cout << "Record has been updated successfully" <<endl;
	}
	getchar();
};

void read(){ //for reading the file, calls the background reading function
	record.readFile();
};

void write(){ //for writing the file, calls the background writing function
	record.writeFile();
};
