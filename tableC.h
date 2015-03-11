#ifndef TABLEC_H
#define TABLEC_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

const int MAX_SIZE = 101;

struct bucket{
	double data;
	bool flag;
};

class tableC{
private:
	bucket a[MAX_SIZE];
	int m;

public:
	tableC();
	int hash(double x);
	void insert(double x);
	void remove(double x);
	void print();
	int find(double x);
	bool contains(double x);
	bool isfull();
	void build(ifstream& file);
};



#endif
