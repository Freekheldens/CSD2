CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : jack_module.o oscillator.o square.o sine.o saw.o addsynth.o main.o
	$(CC) -o $@ $(CFLAGS) jack_module.o oscillator.o square.o sine.o saw.o addsynth.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
