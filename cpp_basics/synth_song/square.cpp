#include "square.h"

// Constructor
Square::Square() : Oscillator() {
}

// Destructor
Square::~Square() {
}

// Sine wave formula
void Square::tick(double samplerate) {
  phase += frequency / samplerate;
  sample = 1 * (sin(phase * PI_2));

  // "Converting" a sine to a square wave
  if (sample > 0.0)
    sample = amplitude;
  else
    sample = -amplitude;
}
