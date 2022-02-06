/* 
 * Student Name: Pelin Hakverir
 * Student ID : 150140031
 * Date:  13.10.2015
 */   
 
#ifndef RECORDAPPS_H
#define RECORDAPPS_H

#include <stdio.h>
#include "books.h"

#define MAXKAYIT 100

//the list of functions that I will use to create main functions of the main program
struct thelist{
	book_record book[MAXKAYIT]; //record of each book
	void create();
	void readFile();
	void writeFile();
	void add(book_record *);
	int sWriter(char []);
	int sType(char []);
	int sISBN(int);
	void deletion(int kayitno);
	void update(int kayitno, book_record *);
	void list();
	int counter;
};
#endif
