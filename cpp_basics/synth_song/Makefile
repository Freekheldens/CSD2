CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: synth_song

synth_song : jack_module.o oscillator.o square.o sine.o saw.o amsynth.o mixsynth.o melodygen.o main.o
	$(CC) -o $@ $(CFLAGS) jack_module.o oscillator.o square.o sine.o saw.o amsynth.o mixsynth.o melodygen.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f synth_song
