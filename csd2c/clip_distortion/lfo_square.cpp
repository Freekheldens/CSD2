#include "lfo_square.h"

// Constructor
Lfo_square::Lfo_square() : Oscillator() {
}

// Destructor
Lfo_square::~Lfo_square() {
}

// Sine wave formula
void Lfo_square::tick(double samplerate) {
  phase += frequency / samplerate;
  sample = (0.5 * (sin(phase * PI_2)) + 0.5);

  // "Converting" a sine to a square wave
  if (sample > 0.5)
    sample = 1;
  else
    sample = 0;
}
