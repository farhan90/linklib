CC=gcc
CFLAGS=-Wall -Werror



all : prog

prog : linklib.o test.o
	$(CC) $(CFLAGS) linklib.o test.o -o prog

test.o : test.c linklib.h
	$(CC) $(CFLAGS) -c test.c

linklib.o : linklib.h linklib.c
	$(CC) $(CFLAGS) -c linklib.c


clean:
	rm -rf *.o prog



