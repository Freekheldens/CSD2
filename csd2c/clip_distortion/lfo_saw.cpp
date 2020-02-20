#include "lfo_saw.h"

// Constructor
Lfo_saw::Lfo_saw() : Oscillator() {
}

// Constructor
Lfo_saw::~Lfo_saw() {
}

// Saw wave formula
void Lfo_saw::tick(double samplerate) {
  phase += frequency / samplerate;
  sample = (((fmod(phase,1)*2)-1) * 0.5) + 0.5;
}
