#include <iostream>
#include "list.h"
using namespace std;

list::list(){
	head = NULL;
	flag = false;
}

list::~list(){
	node *temp = head;
	while (temp != NULL){
		node *temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	head = NULL;
	temp = NULL;
}

//adds node to end of list if it is not already in the list
void list::insert(double x, node *&L){
	if (L == NULL){	//if current node is NULL adds new node with data
		L = new node;
		L->data = x;
		L->next = NULL;
	}
	else{
		if (L->data == x){	//if current node is not null and is the number being inserted 
			cout <<  "Number already in list \n";
		}
		else{	//if current node is not null, last node with data, and not number being inserted, then adds new node with data
			if (L->next == NULL){
				L->next = new node;
				L->next->next = NULL;
				L->next->data = x;
			}
			else{	// current node is not last node and does not contain the number being inserted, then move on to next node recursively
				insert(x, L->next);
			}
		}
	}
}

//checks if list is empty
bool list::isEmpty(){
	if (head == NULL){
		return true;
	}
	else{
		return false;
	}
}

//removes node from list if there
void list::erase(double x, node *&L){
	node *temp = find(x, L);
	if ((temp == NULL)&&(flag == false)) {
		cout << "Number not in List \n";
	}
	else{
		if (temp->next == NULL){	//node is last in list
			if (flag == true){ // last in list and number being found
				head = NULL;
			}
			else{ // last in list and not number being found
			cout << "Number not in List \n";
			}
				
		}
		else{
			if (temp->data == x){	//node returned is the node
				node *temp2 = head->next;
				delete head;
				head = temp2;
			}
			else{	//next node of node returned is the node to be erased
				node *temp2 = temp->next;
				temp->next = temp->next->next;
				delete temp2;
			}
		}
	}

}

//prints current list
void list::print(){
	node *temp = head;	//new node pointing to head
	if (temp == NULL){
		cout << "Empty List \n";
		}
	else{
		while (temp->next != NULL){		//while next node isn't null print data
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data << endl;	//print last node
	}
}

//finds a node in list, returns the node or the node pointing to it
node*& list::find(double x, node *&L){
	//node *notThere;
	//notThere = NULL;
	if (L == NULL){ //first node is null
		flag = false;
		return L;//
	}
	else{
		if (L->next == NULL){	//Node is last in list
			if (L->data == x){	//Found number
				flag = true;
				return L;
			}
			else{	//Node is last in list and not number being found
				flag = false;
				return L;//
			}
		}
		else{
			if (L->next->data == x){ //Node is not last in list and the next node contains number being searched for 
				flag = true;
				return L;
			}
			else if (L->data == x){ // Node is not last in list and is number being searched for (first node contains the number)
				flag = true;
				return L;
			}
			else {	//Node is not last in list node is and next node is not the number being searched for. move to next node
				find(x, L->next); 
			}
		}
	}
}

//builds initial list 
void list::build(ifstream& file){
	double item;
	while (file >> item){//read from file and add each number to head
		insert(item, head);
	}
}

node*& list::getHead(){
	return head;
}
