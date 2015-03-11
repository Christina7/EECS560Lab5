#ifndef TABLEO_H
#define TABLEO_H

#include "list.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class tableO{
private:
	list* a;
	int m;

public:
	tableO();
	~tableO();
	int hash(double x);
	void insert(double x);
	void remove(double x);
	void print();
	bool find(double x);
	void build(ifstream& file);
	list*& getArray();

};



#endif
