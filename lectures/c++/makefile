testrect: testdriver.o rectangle.o
	g++ -Wall -o testrect testdriver.o rectangle.o

rectange.o: rectangle.h rectangle.cpp
	g++ -Wall -c rectangle.cpp

testdriver.o: testdriver.cpp rectangle.h
	g++ -Wall -c testdriver.cpp

clean:
	rm -f testrect *.o