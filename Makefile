CC=gcc
CFLAGS=-Wall -Werror -pedantic -std=c99

dt: dt.o
	$(CC) -o dt dt.o

clean:
	rm dt.o dt
