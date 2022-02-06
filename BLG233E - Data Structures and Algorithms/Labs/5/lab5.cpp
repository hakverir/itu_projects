#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define LENGTH 20

using namespace std;

struct numbers{
	char type[LENGTH];
	char number[LENGTH];
	numbers* next;
};

struct person{
	char name[LENGTH];
	person * next;
	person * prev;
	numbers * num;
};

person* head, *tail;
void sort(person* newperson){
	person* temp;
	
	
	if(head == NULL){
		head = newperson;
	}
	else if(head->next == NULL){
		
		if(strcmp(head->name, newperson->name) == 1 ){
			newperson->next = head;
			head->prev = newperson;
			head = newperson;	
		}
		else{
			head->next = newperson;
			newperson->prev = head;
		}
		
	}
	else{
		
		temp = head;
		
		while(temp != NULL){
			if(strcmp(temp->name, newperson->name) == 1){
				if(temp == head){
					head->prev = newperson;
					newperson->next = head;
					head = newperson;
					break;		
				}
				else{
					temp->prev->next = newperson;
					newperson->prev = temp->prev;
					newperson->next = temp;
					temp->prev = newperson;
					break;
				}
			}
			else if(temp->next == NULL){
				temp->next = newperson;
				newperson->prev = temp; 
				break;
			}
			temp = temp->next;
		}
		
	}	
}

void addPerson(){
	char name[LENGTH];
	person * newperson, *temp;
	
	newperson = new person;
	newperson->next = NULL;
	newperson->prev = NULL;
	newperson->num = NULL;
		
	cout << "Name: ";
	cin.ignore(1000, '\n');
	cin.getline(name, LENGTH);
	
	strcpy(newperson->name, name);
	
	
	sort(newperson);
	
	getchar();
}

void addNumber(){
	char name[LENGTH];
	person* temp;
	numbers* temp2, *temp3;
	bool bulundu = false;
	
	cout << "Name: ";
	cin.ignore(1000, '\n');
	cin.getline(name, LENGTH);
	
	
	temp = head;
	
	while(temp != NULL){
		if(strcmp(temp->name, name) == 0){
			
			temp2 = temp->num;
			
			//numara listesinin sonuna gitme
			while(temp2 !=NULL){
				if(temp2->next == NULL){
					break;
				}
				temp2 = temp2->next;
			}
			
			//yeni numarayý alma
			temp3 = new numbers;
			temp3->next = NULL;
			
			cout << "Type of number (Work, Home, Mobile): ";
			cin.getline(name, LENGTH);	
			
			strcpy(temp3->type, name);
			
			cout << "Number: ";
			cin.getline(name, LENGTH);
			
			strcpy(temp3->number, name);
			
			if(temp2 == NULL){
				temp->num = temp3;
			}
			else{
				temp2->next = temp3;
			}
			
			bulundu = true;//bulunup bulunmama kontrolü
		}
		
		temp = temp->next;
	}
	
	if(!bulundu){
			cout << "Name could not be found" << endl;
	
		}
	
	getchar();
}

void removePerson(){
	char name[LENGTH];
	person* temp;
	numbers* tutucu, *temp2;
	
	cout << "Name: ";
	cin.ignore(1000, '\n');
	cin.getline(name, LENGTH);
	
	temp = head;
	
	while(temp != NULL){
		if(strcmp(temp->name, name) == 0){
			if(temp == head){
				if(temp->next != NULL){
					
					temp2 = temp->num;
					while(temp2 != NULL){
						tutucu = temp2;
						temp2 = temp2->next;
						delete(tutucu);	
					}
					
					head = head->next;
					head->prev = NULL;
					delete(temp);
				}
				else{
					temp2 = temp->num;
					while(temp2 != NULL){
						tutucu = temp2;
						temp2 = temp2->next;
						delete(tutucu);	
					}
					delete(temp);
					head = NULL;
				}
			}
			
			else if(temp->next == NULL){
				temp2 = temp->num;
				while(temp2 != NULL){
					tutucu = temp2;
					temp2 = temp2->next;
					delete(tutucu);	
				}
				temp->prev->next = NULL;
				delete(temp);
			}
			
			else{
				
				temp2 = temp->num;
				while(temp2 != NULL){
					tutucu = temp2;
					temp2 = temp2->next;
					delete(tutucu);	
				}
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete(temp);
			}
			
		}
		temp = temp->next;
	}
	getchar();
}

void updatePerson(){
	char name[LENGTH];
	person* temp;
	
	cout << "Name: ";
	cin.ignore(1000, '\n');
	cin.getline(name, LENGTH);
	
	temp = head;
	
	while(temp != NULL){
		if(strcmp(temp->name, name) == 0){
			if(temp == head){
				cout << "Name: ";
				cin.getline(name, LENGTH);
				
				strcpy(temp->name, name);
				break;
			}
			else if(temp->next != NULL){
				cout << "Name: ";
				cin.getline(name, LENGTH);
				
				strcpy(temp->name, name);
				
				//listeden koparýp sortlama
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				
				temp->prev = NULL;
				temp->next = NULL;
				sort(temp);
				break;
			}
			else{
				cout << "Name: ";
				cin.getline(name, LENGTH);
				
				strcpy(temp->name, name);
				
				//listeden koparýp sortlama
				temp->prev->next = NULL;
				
				temp->prev = NULL;
				temp->next = NULL;
				
				sort(temp);	
				break;	
			}	
		}
		temp = temp->next;
	}
	getchar();
}

void updateNumber(){
	char name[LENGTH], number[LENGTH];
	person* temp;
	numbers * temp2;
	int index = 1;
	int input;
	
	cout << "Name: ";
	cin.ignore(1000, '\n');
	cin.getline(name, LENGTH);
	
	temp = head;
	
	while(temp != NULL){
		if(strcmp(temp->name, name) == 0){
			temp2 = temp->num;
			
			cout<< "Select the number you want to update"<< endl;
			
			//numaralarý yazdýrma
			while(temp2 != NULL){
				cout << index <<"."<< temp2->number<< endl; 		
				temp2 = temp2->next;
				index++;	
			}
			
			cin >> input;
			
			index = 1;
			temp2 = temp->num;
			
			while(temp2 != NULL){
				if(index == input){
					
					cout << "New number: " << endl;
					cin.ignore(1000, '\n');
					cin.getline(number, LENGTH);
					
					strcpy(temp2->number, number);
					break;
				}
					
				index++;
				temp2 = temp2->next;	
			}
			break;
			
		}
		
		temp = temp->next;
	}
				
	getchar();
}

void search(){
	
	getchar();
}

void list(){
	person* temp;
	numbers* temp2;
	
	temp = head;
	
	while(temp!= NULL){
		cout<<"Name: " << temp->name << endl;	
		
		temp2 = temp->num;
		
		while(temp2 != NULL){
			cout << "Type: " << temp2->type << "   Number: " << temp2->number << endl;
			temp2 = temp2->next;
		}
		
		cout << endl;
		temp = temp->next;
	}
	
	
	getchar();
}

void ext(){
	person* temp, *silici;
	numbers* temp2, *tutucu;
	
	temp = head;
	
	while(temp!= NULL){
		
		temp2 = temp->num;
		
		while(temp2 != NULL){
			tutucu = temp2;
			temp2 = temp2->next;
			delete(tutucu);
			
		}
		
		silici = temp;
		temp = temp->next;	
		delete(silici);		
	}
	
	getchar();
	exit(1);
}




int main(){
	char secim;
	
	while(1){
	
		cout<< "*******************\n*\n"
		"* {P} Add Person\n"
		"* {N} Add Person\n"
		"* {R} Add Number to Person\n"
		"* {U} Update Person\n"
		"* {T} Update Numbers\n"
		"* {S} Search by name\n"
		"* {L} List the all contacts\n"
		"* {E} Exit\n*\n" 
		"*******************\n"<< endl;
		cin>>secim ;
		switch(secim){
			case 'P': case'p':
				addPerson();
				break;
			case 'N': case'n':
				addNumber();
				break;
			case 'R': case'r':
				removePerson();
				break;
			case 'U': case'u':
				updatePerson();
				break;
			case 'T': case't':
				updateNumber();
				break;
			case 'S': case's':
				search();
				break;
			case 'L': case'l':
				list();
				break;
			case 'E': case'e':
				ext();
				break;
			default:
				ext();
				break;	
		}
	
	}
}

