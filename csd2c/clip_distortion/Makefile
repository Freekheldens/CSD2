CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: example

example : jack_module.o main.o oscillator.o sine.o lfo_sine.o lfo_square.o lfo_saw.o
	$(CC) -o $@ $(CFLAGS) jack_module.o main.o oscillator.o sine.o lfo_sine.o lfo_square.o lfo_saw.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
