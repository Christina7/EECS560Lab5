#include "tableO.h"
#include "Timer.cpp"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;


tableO::tableO(){
	m = 10;
	a = NULL;
}

tableO::~tableO(){
	delete [] a;
	a = NULL;
}

int tableO::hash(double x){
	int index = int(x) % m;
	return index;
}

void tableO::insert(double x){	//uses list method to insert after finding correct index
	int index = hash(x);
	a[index].insert(x, a[index].getHead());
}

void tableO::remove(double x){	//looks for hash index removes with list method
	bool isThere = find(x);
	int index = hash(x);
	if (isThere == true){
		a[index].erase(x, a[index].getHead());
	}
	else{
	//	cout << "Number not in tableO";
	}
}

void tableO::print(){	//uses list method's print
	for (int i = 0; i < m; i++){
		cout << i << ": ";
		a[i].print();
		cout << endl;
	}
}

bool tableO::find(double x){	//finds hash index looks in that list
	int index = hash(x);
	node* temp = a[index].getHead();
	while (temp != NULL){
		if (temp->data == x){
			return true;
		}
		else{
			temp = temp->next;
		}
	}
	return false;

}


//need to edit so for given numbers do timing here
void tableO::build(double itemnum, int seed, double size){
	
	srand( seed );

	Timer time;
	int item;
	double clock = 0;	

	int i = 0;
	a = new list[int(size)];
	
	//cout << loadfactor;

	while (i < itemnum){
		item  = rand()%2147483648; 	
		time.start();
		insert(item);
		clock += time.stop();
	}
	
	cout << clock << endl;

}

list*& tableO::getArray(){
	return a;
}
