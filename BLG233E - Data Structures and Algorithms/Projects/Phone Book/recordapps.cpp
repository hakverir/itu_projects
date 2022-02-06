/* 
 * Student Name: Pelin Hakverir
 * Student ID : 150140031
 * Date:  13.10.2015
 */   
 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>

#include "recordapps.h"

using namespace std;

//the background of the functions that I will use in the main program

void thelist::readFile(){ //reading the file of the books' records. if not exists, creates
	FILE *kopyaDosya;
	book_record temp;
	if((kopyaDosya = fopen("bookrecords.txt","r"))==NULL){
		if((kopyaDosya=fopen("bookrecords.txt", "w"))==NULL){
			printf("File could not be opened\n");
		}	
	}
		else{
			while(!feof(kopyaDosya)){
				fscanf(kopyaDosya, "%23s%23s%23s", &book[counter].authorName, &book[counter].authorSurname, &book[counter].title);
				fscanf(kopyaDosya, "%8d%7d%13s", &book[counter].ISBN, &book[counter].location, &book[counter].bookType);
				counter++;
			}
			counter--;
	}
	fclose(kopyaDosya);
}

void thelist::writeFile(){ //writing the edited/created book records to the file
	FILE *sonucDosya;
	if((sonucDosya = fopen("bookrecords.txt","a"))==NULL)
		printf("File could not be opened\n");
	else{
			for(int i=0;i<counter;i++){
				if(strcmp(book[i].title,"")==0 && strcmp(book[i].authorName,"")==0) continue; //eliminating the blank records
				fprintf(sonucDosya, "%-23s%-23s%-23s", book[i].authorName, book[i].authorSurname, book[i].title);
				fprintf(sonucDosya, "%-8d%-7d%-13s\n", book[i].ISBN, book[i].location, book[i].bookType);
			}
		}
	fclose(sonucDosya);
}

void thelist::add(book_record *ykptr){ //adding new records to the list
	strcpy(book[counter].authorName,ykptr->authorName);
 	strcpy(book[counter].authorSurname,ykptr->authorSurname);
 	strcpy(book[counter].title,ykptr->title);
 	book[counter].ISBN=ykptr->ISBN;
 	book[counter].location=ykptr->location;
 	strcpy(book[counter].bookType,ykptr->bookType);
	counter++;
}

void thelist::create(){ //creating the list from the beginning
	counter=0;
}


int thelist::sWriter(char aranacak[]){ //searching by the author's name
	int found=0; //to make sure the program that a record is found or not
	
	if(strcmp(aranacak,"*")==0){ //listing all books
		for(int i=0;i<counter;i++){
			 printf("%d. %-23s%-23s%-23s\n", i+1, book[i].authorName, book[i].authorSurname, book[i].title);
			 found=1;
		}
	}
	   
	else { //listing a specific author's books
		for(int i=0;i<counter;i++)
		{
 			if((strcmp(book[i].authorName,aranacak)==0))
				{
				 printf("%d. %-23s%-23s%-23s\n", i+1, book[i].authorName, book[i].authorSurname, book[i].title);
 				 found=i;
				 found=1;
				}
		}
	}
return found;
}

int thelist::sType(char aranacak[]){ //searching by the book's type
	int found=0; //to make sure the program that a record is found or not
	
	if(strcmp(aranacak,"*")==0){ //listing all books
		for(int i=0;i<counter;i++){
			printf("%d. %-13s%-23s%-23s%-23s\n", i+1, book[i].bookType, book[i].authorName, book[i].authorSurname, book[i].title);
			 found=1;
		}
	}
	   
	   
	else { //listing a specific type's books
		for(int i=0;i<counter;i++)
		{
 			if(strcmp(book[i].bookType,aranacak)==0)
				{
				 printf("%d. %-13s%-23s%-23s%-23s\n", i+1, book[i].bookType, book[i].authorName, book[i].authorSurname, book[i].title);
 				 found=i;
				 found=1;
				}
		}
	}
return found;
}

int thelist::sISBN(int aranacak){//searching by the book's ISBN number
	int found=0;
	
	if(aranacak==0){ //listing all books
		for(int i=0;i<counter;i++){
			 printf("%d. %-23s%-23s%-23s\n", i+1, book[i].authorName, book[i].authorSurname, book[i].title);
			 found=1;
		}
	}
	
	else { //listing books with specific ISBN numbers
		for(int i=0;i<counter;i++)
		{
 			if(book[i].ISBN==aranacak)
				{
				 printf("%d. %-23s%-23s%-23s\n", i+1, book[i].authorName, book[i].authorSurname, book[i].title);
				 found=1;
				}
		}
	}
return found;
}

void thelist::update(int kayitno, book_record *ykptr){ //updating an existing record
	strcpy(book[kayitno-1].authorName,ykptr->authorName);
	strcpy(book[kayitno-1].authorSurname,ykptr->authorSurname);
	strcpy(book[kayitno-1].title,ykptr->title);
	book[kayitno-1].ISBN=ykptr->ISBN;
	book[kayitno-1].location=ykptr->location;
	strcpy(book[kayitno-1].bookType,ykptr->bookType);
}

void thelist::deletion(int kayitno){ //deleting an existing record
	book_record temp;
	strcpy(temp.authorName, "");
	strcpy(temp.authorSurname, "");
	strcpy(temp.title, "");
	temp.ISBN=0;
	temp.location=0;
	strcpy(temp.bookType, "");
	int indisno;
	indisno=kayitno-1;
	book[indisno] = temp;
}

void thelist::list(){ //listing all record with all members
	for(int i=0;i<counter;i++){
		printf("%d. %-23s%-23s%-23s%-8d%-7d%-13s\n", i+1, book[i].authorName, book[i].authorSurname, book[i].title, book[i].ISBN, book[i].location, book[i].bookType);
	}
}

