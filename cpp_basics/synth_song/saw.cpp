#include "saw.h"

// Constructor
Saw::Saw() : Oscillator() {
}

// Constructor
Saw::~Saw() {
}

// Saw wave formula
void Saw::tick(double samplerate) {
  phase += frequency / samplerate;
  sample = ((fmod(phase,1)*2)-1) * amplitude;
}
