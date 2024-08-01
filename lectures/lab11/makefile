all: td

td: testdriver.o list.o 
	g++ -Wall -o td testdriver.o list.o

testdriver.o: testdriver.cpp list.h
	g++ -Wall -c testdriver.cpp

list.o: list.cpp list.h
	g++ -Wall -c list.cpp

clean:
	rm -f td *.o