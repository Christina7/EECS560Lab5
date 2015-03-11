lab5: lab5.o list.o Timer.o
	g++ -g -std=c++11 lab5.o tableO.o list.o tableC.o Timer.o -o lab5

lab5.o: lab5.cpp tableO.o tableC.o
	g++ -c -g -std=c++11 lab5.cpp

tableO.o: tableO.cpp list.o Timer.o
	g++ -c -g -std=c++11 tableO.cpp

list.o: list.cpp 
	g++ -c -g -std=c++11 list.cpp
	
tableC.o: tableC.cpp Timer.o
	g++ -c -g -std=c++11 tableC.cpp
	
Timer.o: Timer.cpp 
	g++ -c -g -std=c++11 Timer.cpp

clean:
	rm -f *~ *.o
