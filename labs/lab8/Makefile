CFLAGS = -std=c99 -g -Wall -O3
LDFLAGS = -lm -lpng

LDFLAGS += 'pkg-config --libs x11'
CFLAGS += 'pkg-config --cflags x11'

dstr = dataStructure.c testdriver.c
dst: $(dstr) dataStructure.h
	gcc $(CFLAGS) -o dst $(dstr) $(LDFLAGS)

clean:
	rm -f dst *-o