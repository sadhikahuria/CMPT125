all: testcirc

testcirc: testcirc.o Circle.o
	g++ -Wall -o testcirc testcirc.o Circle.o

Circle.o: Circle.cpp Circle.h
	g++ -Wall -c Circle.cpp 

testcirc.o: testcirc.cpp Circle.h
	g++ -Wall -c testcirc.cpp

clean: 
	rm -f testcirc *.o