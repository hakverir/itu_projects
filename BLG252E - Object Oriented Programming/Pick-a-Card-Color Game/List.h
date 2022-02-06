//Pelin Hakverir
//150140031

#include "Cards.h"
#include <iostream>

using namespace std;

class ListNode{
	friend class HetList;

	ListNode *next;
public:
    Cards *card;
    ListNode *GetNext() { return next; }
	ListNode(Cards&);
};

ListNode::ListNode(Cards &n){
	card = &n;
	next = NULL;
}

class HetList{
	ListNode *head;
public:
    HetList(){ head = NULL; }
	~HetList();
    void Insert(Cards &t);
    ListNode* getHead(){ return head; }
};

HetList::~HetList(){
    /*ListNode *p = head;
	while (head){
		head = head->next;
		delete p;
		p = head;
    }*/
}

void HetList::Insert(Cards &t){
    ListNode *newnode , *temp;
    if (head){
        newnode = new ListNode(t);
        temp = head;
        newnode->next = temp;
        head = newnode;
	}
	else{
        head = new ListNode(t);
		head->next = NULL;
	}
}
