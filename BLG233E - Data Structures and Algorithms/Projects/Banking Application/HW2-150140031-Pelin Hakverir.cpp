/*
  * @Author
    * Student Name: Pelin Hakverir
	  * Student ID : 150140031
	    * Date:  8.11.2015
*/   

#define MAX 100

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>


using namespace std;

struct transactions{
	char tName[MAX];
	transactions *next;
};

struct customers{
	char name[MAX], surname[MAX], type;
	int transactionNumber;
	customers *next;
	transactions *transaction;
}*head;

void add(char *, char *, char, char *);
void process();
void search(char *, char *);
void remove(char *, char *, char);
void print();
customers* createCustomer(char *, char *, char, char *, int);
void stringSeparate(int);
void emptyArrays();
void deletion();

char arrName[MAX]=" ";
char arrSurname[MAX]=" ";
char custType;
char traName[MAX]=" ";
int traNum=0;
int j = 0;

char choice;
char inputstring[MAX];

int main(){

	head=NULL;
	if (!(freopen("input_file.txt", "r", stdin))){
		cout<<"File could not be opened (input)\n"<<endl;
	}

	if (!(freopen("output_file.txt", "w+", stdout))){
		cout<<"File could not be opened (output)\n"<<endl;
	}

	while (1){

		cin>> inputstring;
		choice = inputstring[0];

		switch (choice){
		case 'A': case 'a':
			stringSeparate(1);
			add(arrName, arrSurname, custType, traName);
			emptyArrays();
			break;
		case 'V': case 'v':
			process();
			emptyArrays();
			break;
		case 'S': case 's':
			stringSeparate(2);
			search(arrName, arrSurname);
			emptyArrays();
			break;
		case 'R': case 'r':
			stringSeparate(3);
			remove(arrName, arrSurname, custType);
			emptyArrays();
			break;
		case 'P': case 'p':
			print();
			emptyArrays();
			break;
		case 'E': case 'e':
			cout<< "Program exits\n"<<endl;
			break;
		default:
			cout<<"Invalid choice. Try Again.\n"<<endl;
		}
	 if (choice == 'E') {
	 	deletion();
		fclose(stdin);
		fclose(stdout);
		return 0;
	 }
	}
}

customers* createCustomer(char *name, char *surname, char Type, char *tran, int Number){
	char arr[MAX];
	customers *newCustomer;
	transactions *newTransaction;

	newCustomer = new customers;
	strcpy(newCustomer->name, name);
	strcpy(newCustomer->surname, surname);
	newCustomer->type = Type;
	newCustomer->transactionNumber=Number;

	newTransaction = new transactions;
	newCustomer->transaction = newTransaction;

	for(int i = 0;tran[i]!='\0' || tran[i]!='\n';i++){
		for(int j=0;tran[i]!=' ' && tran[i]!='\0' && tran[i]!='\n'; i++, j++){
			arr[j]=tran[i];
			arr[j+1]=0;
		}
		strcpy(newTransaction->tName,arr);
		for(int k=0;k<MAX; k++) arr[k]=0;
		if(tran[i+1]=='\0' || tran[i+1]=='\n') break;
		newTransaction->next = new transactions;
		newTransaction = newTransaction->next;
	}
	
	newCustomer->next = NULL;
	newTransaction->next = NULL;
	return newCustomer;
}

void add(char *Name, char *Surname, char Type, char *Tras){
	customers *traverse, *tail, *customerInfo;
	traverse = head;
	
	if (head == NULL) { //baþa ekleme, liste boþ
		head = createCustomer(Name, Surname, Type, Tras, traNum);
		cout<< "New customer is added"<<endl<<endl;
		return;
	}
	
	else if(Type=='N'){
		customerInfo = createCustomer(Name, Surname, Type, Tras, traNum);
		while (traverse){
				tail=traverse;
				traverse = traverse->next;
			}
		tail->next=customerInfo;
		customerInfo->next=NULL;
	}
	
	else if(Type>(traverse->type)){
		customerInfo = createCustomer(Name, Surname, Type, Tras, traNum);
		customerInfo->next=head;
		head=customerInfo;
	}
	
	else if(Type==traverse->type){
		while (traverse && (Type <= traverse->type)) { //liste boþ deðil, p var ve p ekliyorum || n var ve n ekliyorum || p var n ekliyorum
			tail = traverse; //p de kaldý tail
			traverse = traverse->next; //traverse n de
		}
		if(traverse){
			customerInfo = createCustomer(Name, Surname, Type, Tras, traNum);
			customerInfo->next = traverse;
			tail->next = customerInfo;
		}
		else{
			customerInfo = createCustomer(Name, Surname, Type, Tras, traNum);
			tail->next=customerInfo;
			customerInfo->next=NULL;
		}
	}
	cout<< "New customer is added"<<endl<<endl;
	return;
}

void process(){
	customers *traverse, *tail, *customer;
	transactions *tr;
	traverse = head;
	tr = traverse->transaction;
	customer = traverse;

	if (traverse->type == 'P'){//müþteri sýralamadaki iþlem, son p ve ilk n nin arasýna sokacak, ilk tName ini silecek

		if (traverse->transactionNumber == 1){//sýradan çýkartacak, tamamen silecek
			head = head->next;
			delete tr;
			delete traverse;
		}

		else if (traverse->transactionNumber > 1){//ilk iþlemini silecek, son p ve ilk n nin arasýna sokacak, ilk tName ini silecek, transactionNumber azalacak
			traverse->transaction = tr->next;
			delete tr;
			tr = traverse->transaction;
			(traverse->transactionNumber)--;
			
			if (traverse->next == NULL || traverse->next->type == 'N') {//baþka müþteri yoksa veya hemen sonra n varsa
				cout<< "Next transaction is processed"<<endl<<endl;
				return;
			}
			
			else{
				while (customer->type == traverse->type) {
					tail = traverse; //p de kaldý tail
					traverse = traverse->next; //traverse n de
				}
				
				if (traverse->type == 'N'){ //n ye gelmiþse
						head=head->next;
						customer->next = traverse;
						tail->next = customer;
					}
				else if (traverse == NULL){//bütün liste p ise
					head = head->next;
					tail->next=customer;
					customer->next=NULL;
				}
			}
		}
	}

	else if (traverse->type == 'N'){
		if (traverse->transactionNumber == 1){//sýradan çýkartacak, tamamen silecek
			head = head->next;
			delete tr;
			delete traverse;
		}

		else if (traverse->transactionNumber > 1){//ilk iþlemini silecek, sýrasý deðiþmeyecek, tranumber azalacak
			traverse->transaction = tr->next;
			delete tr;
			tr = traverse->transaction;
			(traverse->transactionNumber)--;
		}
	}
	cout<< "Next transaction is processed"<<endl<<endl;
	return;
}

void search(char *Name, char *Surname){//ikiye ayýr 0sa search 1se remove yapsýn

	customers *traverse;
	transactions *trInfo;
	int counter = 0;
	int found = 0;
	traverse = head;

	while (traverse) {
		counter++;

		if (strncmp(Name, traverse->name, strlen(Name)) == 0) {
			if (strncmp(Surname, traverse->surname, strlen(Surname)) == 0){
				found++;
				cout<< counter<< ". "<< traverse->name<< " "<<traverse->surname;
				trInfo = traverse->transaction;
				while (trInfo) {
					cout<< " "<<trInfo->tName;
					trInfo = trInfo->next;
				}
				cout<<endl<<endl;
			}
		}
		traverse = traverse->next;
	}

	if (found == 0){
		cout<< Name<<" "<<Surname<<" could not be found\n"<<endl<<endl;
	}
	return;
}


void remove(char *Name, char *Surname, char Type){
	customers *traverse, *tail;
	transactions *tr;
	traverse = head;
	int transactioncount = 0;

	while (traverse) {
		if (strncmp(Name, traverse->name, strlen(Name)) == 0) {
			if (strncmp(Surname, traverse->surname, strlen(Surname)) == 0){
				if (Type == traverse->type){
					break;
				}
			}
		}
		tail = traverse;
		traverse = traverse->next;
	}

	if (!traverse){//bulunamazsa
		cout<< Name<<" "<< Surname<<" with "<< Type<< " customer type could not be found"<<endl<<endl;
		return;
	}

	else if (traverse == head){//ilk elemanýn silinmesini isterse
		head = head->next;
		tr = traverse->transaction;
		while (tr){
			traverse->transaction = tr->next;
			delete tr;
			tr = traverse->transaction;
		}
		delete traverse;
		cout<<Name<<" " <<Surname<<" is removed"<<endl<<endl;
		return;
	}

	else {//ilk eleman deðilse
		tail->next = traverse->next;
		tr = traverse->transaction;
		while (tr) {
			traverse->transaction = tr->next;
			delete tr;
			tr = traverse->transaction;
		}
		delete traverse;
		cout<<Name<<" "<<Surname<< " is removed"<<endl<<endl;
		return;
	}
}

void print(){
	customers *traverse;
	transactions *tr;
	traverse = head;

	while (traverse){
		tr = traverse->transaction;
		cout<< traverse->name<<" "<< traverse->surname<<" "<< traverse->type;
		while (tr){
			cout<<" " << tr->tName;
			tr = tr->next;
		}
		cout<<endl;
		traverse=traverse->next;
	}
	cout<<endl;
	
	return;
}

void stringSeparate(int func){
	
	if (func == 1){//add
		
		int i = 2, j=0;
		for (; inputstring[i] != ';'; i++, j++)
			arrName[j] = inputstring[i];
		j = 0;
		
		for (i += 1; inputstring[i] != ';'; i++, j++)
			arrSurname[j] = inputstring[i];
		j = 0;
		custType = inputstring[i += 1];
		i+=2;
		char arr[2];
			arr[0]=inputstring[i];
			traNum=atoi(arr);
			
			if (inputstring[i+1] == ';'){
				if (inputstring[i] > '1'){
					i += 2;
					for(int j=0;inputstring[i] != '\0' && inputstring[i] != '\n';i++,j++){
						if(inputstring[i] == ';') inputstring[i] = ' ';
						traName[j] = inputstring[i];
					}
				}

				else{
					for (i += 2; inputstring[i] != '\n' && inputstring[i] != '\0'; i++, j++)
						traName[j] = inputstring[i];
				}
			}
			else{
				i += 3;
					for(int j=0;inputstring[i] != '\0' && inputstring[i] != '\n';i++,j++){
						if(inputstring[i] == ';') inputstring[i] = ' ';
						traName[j] = inputstring[i];
					}
			}
	}
		
	if (func == 2){// search
		int i = 2, j = 0;
		for (; inputstring[i] != ';'; i++, j++)
			arrName[j] = inputstring[i];
		j = 0;

		for (i += 1; inputstring[i] != ';' && inputstring[i] != '\0' && inputstring[i] != '\n'; i++, j++)
			arrSurname[j] = inputstring[i];
		j = 0;
		}

	if(func==3){//remove
		int i = 2, j=0;
		for (; inputstring[i] != ';'; i++, j++)
			arrName[j] = inputstring[i];
		j = 0;
		
		for (i += 1; inputstring[i] != ';' && inputstring[i] != '\0' && inputstring[i] != '\n'; i++, j++)
			arrSurname[j] = inputstring[i];
		j = 0;
			custType = inputstring[i += 1];
		}

}

void emptyArrays(){
	for (int k = 0; k < sizeof(arrName); k++) arrName[k] =0;
	for (int k = 0; k < sizeof(arrSurname); k++) arrSurname[k] =0;
	custType = ' ';
	for (int k = 0; k < sizeof(traName); k++) traName[k] =0;
	for (int k = 0; k < sizeof(inputstring); k++) inputstring[k] =0;
	return;
}

void deletion(){
	if(head==NULL) return;
	customers *x;
	transactions *y;
	x = head;

	while(x){
		head=head->next;
		y=x->transaction;
		while(y){
			x->transaction=y->next;
			delete y;
			y=x->transaction;
		}
		delete x;
		x = head;
	}
}
