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
	unsigned long m;

public:
	tableO();
	~tableO();
	int hash(double x);
	void insert(double x);
	void remove(double x);
	void print();
	bool find(double x);
	void build(double itemnum, int seed, double size);
	list*& getArray();

};



#endif
