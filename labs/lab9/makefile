CC=gcc
CFLAGS=-I.
DEPS = dataStructure.h
OBJ = dataStructure.o testdriver.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testdriver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o testdriver
