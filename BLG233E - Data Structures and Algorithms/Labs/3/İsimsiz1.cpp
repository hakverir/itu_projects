#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int n, final;

struct records{
	*name, *surname, *number;
} *array, *temp;


inline void add();
inline void remove();
inline void list();

int maint(){
	
	array=new records[n];
	
	while(22){
		char choice;
		cout<<"*******Phone Book Application*******"<<endl;
		cout<<"(P) Print all catalogue"<<endl;
		cout<<"(A) Add new record"<<endl;
		cout<<"(R) Remove record"<<endl;
		cout<<"(E) Exit"<<endl;
		cout<<"Please select an option: ";
		cin>>choice;
		
		if(final==n-1){
			
			n*=2;
			temp=array;
			array=new records[n];
			
			for( int i=0 ; i<cur ; i++ )
				array[i]=temp[i];
		}
		
		if( choice=='A' )
			add();
		else if( choice=='P' )
			list();
		else if(choice=='R')
			remove();
		else if(choice=='E')
			break;
		else 
			cout<<"Invalid option. Please try again."<<endl;
			cout<<endl;
			return while;
	}
	return 0;
}

inline void add(){
	
	char name[30];
	
	cout << "Please enter the information of the person you want to add" << endl;
	cout << "Name: ";
	cin.ignore(1000,'\n');
	cin.getline(name,30);
	
	ar[cur].name=new char[strlen(name)];
	strcpy(ar[cur].name,name);
	
	cout << "Surname: ";
	cin.getline(name,30);
	
	ar[cur].surname=new char[strlen(name)];
	strcpy(ar[cur].surname,name);
	
	cout << "Number: ";
	cin.getline(name,30);
	
	ar[cur].num=new char[strlen(name)];
	strcpy(ar[cur].num,name);
	
	for( int i=cur ; i ; i-- ){
		if( strcmp(ar[i-1].name,ar[i].name)==0 && strcmp(ar[i-1].surname,ar[i].surname)==1 )
			swap(ar[i],ar[i-1]);
		else if( strcmp(ar[i-1].name,ar[i].name)==1 )
			swap(ar[i],ar[i-1]);
		else
			break;
	}
	
	cout << "Record has been added" <<endl;
	cur++;
}

inline void remove(){
	char name[30];
	
	cout << "Please enter the name of the person you want to remove" << endl;
	cin.ignore(1000,'\n');
	cin.getline(name,30);
	
	
	
	
}

inline void list(){
	
	for( int i=0 ; i<cur ; i++ )
		cout << ar[i].name << ' ' << ar[i].surname << ' ' << ar[i].num << endl;
}











