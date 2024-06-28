rec: testdriver.o InRectangle.o
	gcc -o rec testdriver.o InRectangle.o

testdriver.o: testdriver.c
	gcc -Wall -c testdriver.c

InRectangle.o: InRectangle.c
	gcc -Wall -c InRectangle.c

clean:
	rm -f rec *.o