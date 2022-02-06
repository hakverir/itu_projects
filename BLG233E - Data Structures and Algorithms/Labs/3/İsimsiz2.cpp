#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, final;

struct records{
	char *name, *surname, *number;
}*array, *temp;

const int MAX=33;

void add();
void remove();
void list();
void update();
void search(int);
void slideR();
void slideL();
void deleting();

int main(){
	array=new records[n];
	
	while{
		char choice;
		
		cout<<"*******Phone Book Application*******"<<endl;
		cout<<"(P) Print all catalogue"<<endl;
		cout<<"(A) Add new record"<<endl;
		cout<<"(S) Search record"<<endl;
		cout<<"(U) Update record"<<endl;
		cout<<"(R) Remove record"<<endl;
		cout<<"(E) Exit"<<endl;
		cout<<"Please enter your choice: ";
		cin>>choice;
		
		if(final=(n-1)){
			n*=2;
			temp=ar;
			ar=new record[n];
			
			for(int i=0; i<final;i++)
				ar[i]=temp[i];
		}
		
		if()
	}
}
