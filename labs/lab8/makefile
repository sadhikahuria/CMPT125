# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Source files
SRC = dataStructure.c testDriver.c

# Output executable
OUT = testDriver

all: $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)