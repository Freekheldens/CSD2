#include "square.h"
#include "math.h"

Square::Square() : Oscillator() {
  cout << "Sqaure constructor" << endl;
}

Square::~Square() {
  cout << "Square destructor" << endl;
}

// sine wave formula
void Square::tick(double samplerate) {
  phase += frequency / samplerate;
  sample = 1 * (sin(phase * PI_2));

  // "converting" a sine to a square wave
  if (sample > 0.0)
    sample = amplitude;
  else
    sample = -amplitude;
}