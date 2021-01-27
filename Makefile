CC=gcc
CFLAGS=-Wall -Werror -pedantic -std=c99
DEPS = chi.h
LIBS=-lm -I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dt: dt.o chi.o
	$(CC) -o dt dt.o chi.o $(LIBS)

test: test.o chi.o
	$(CC) -o test test.o chi.o $(LIBS)

clean:
	rm *.o dt test
