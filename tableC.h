#ifndef TABLEC_H
#define TABLEC_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

const int max_size = 65521;//65537; // 600011;

struct bucket{
	double data;
	bool flag;
};

class tableC{
private:
	bucket a[max_size];
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
	void build(double itemnum, int seed, double size);
};



#endif
