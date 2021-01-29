CC=gcc
CFLAGS=-Wall -Werror -pedantic -std=c99
LIBS=-lgsl -lm

dt: dt.o
	$(CC) -o dt dt.o $(LIBS)

clean:
	rm -f *.o dt
