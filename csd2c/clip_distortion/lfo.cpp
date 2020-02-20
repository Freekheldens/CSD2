#include "lfo.h"

// Constructor
Lfo::Lfo() : Oscillator() {
}

// Destructor
Lfo::~Lfo() {
}

// sine wave formula
void Lfo::tick(double samplerate) {
  phase += frequency / samplerate;
  sample = (0.5 * (sin(phase * PI_2)) + 0.5);
}
