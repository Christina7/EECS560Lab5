#include <iostream>
#include "tableO.h"
#include "tableC.h"
using namespace std;

int main(){

	tableO ohashtable;
	tableC chashtable;
	
	//tableO ohashtable = new tableO();
	//tableC chashtable =  new tableC();
	
	double loadfactor;
	double size = 65521;//599999; //600011;
	double numitem; 
	
	int seed;
	
	//5 seeds for each load factor(5) avg
	//srand for seed
	for ( int i = 0; i < 5; i++){
		
		switch (i) {
			case 0 :
				loadfactor = .2;
				break;
			
			case 1 :
				loadfactor = .3;
				break;
			
			case 2 :
				loadfactor = .4;
				break;
			
			case 3 :
				loadfactor = .5;
				break;
		
			case 4 :	
				loadfactor = .6;
				break;	
		}
		
		numitem = loadfactor * size;
	
		cout << "Loadfactor " << loadfactor << endl << endl;
	
		for (int j = 0 ; j < 5 ; j++){
		
			switch (j) {
				case 0 :
					seed = 7;
					break;
			
				case 1 :
					seed = 42;
					break;
			
				case 2 :
					seed = 89;
					break;
			
				case 3 :
					seed = 22;
					break;
		
				case 4 :	
					seed = 66;
					break;	
			}			
		
			cout << "Seed "  << seed << endl;		
		
			ohashtable.build(numitem, seed, size); //do timing stuff

			chashtable.build(numitem, seed, size);

			cout << endl << endl;
			
		}
	}

}
