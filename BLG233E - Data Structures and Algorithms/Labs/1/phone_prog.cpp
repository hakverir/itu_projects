#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>

#include "fileoperations.h"

using namespace std;

typedef Dosya Veriyapisi;

Veriyapisi Defter;

void menu_yazdir();
bool islem_yap(char);
void kayit_ara();
void kayit_ekle();
void kayit_sil();
void kayit_guncelle();

int main(){
	defter.olustur();
	bool bitir=false;
	char secim;
	while(!bitir){
		menu_yazdir();
		cin>>secim;
		bitir=islem_yap(secim);
	}
	defter.kapat();
	return EXIT_SUCCESS;
}

void menu_yazdir(){
	system("clear");
	cout<<endl<<endl;
	cout<<"Phone Book Application"<<endl;
	cout<<"Choose an option"<<endl;
	cout<<"A: Search Record"<<endl;
	cout<<"E: Add Record"<<endl;
	cout<<"G: Update Record"<<endl;
	cout<<"S: Delete Record"<<endl;
	cout<<"C: Exit"<<endl;
	cout<<endl;
	cout<<"Enter your option {A, E, G, S, C} : ";
}

bool islem_yap(char secim){
	bool sonlandir=false;
	switch(secim){
		case 'A': case 'a':
				kayit_ara();
				break;
		case 'E': case 'e':
				kayit_ekle();
				break;
		case 'G': case 'g':
				kayit_guncelle();
				break;
		case 'S': case 's':
				kayit_sil();
				break;
		case 'C': case 'c':
				cout<<"Are you sure that you want to terminate the program? (E/H) : ";
				cin>>secim;
				if(secim=='E'||secim=='e')
					sonlandir=true;
					break;
		default:
				cout<<"Error: You have made an invalid choice"<<endl;
				cout<<"Try again {A, E, G, S, C} : ";
				cin>>secim;
				sonlandir=islem_yap(secim);
				break;		
	}
	return sonlandir;
}
