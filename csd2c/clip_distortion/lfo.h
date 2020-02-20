#ifndef _LFO_H_
#define _LFO_H_

#include "oscillator.h"

#include <iostream>
using namespace std;

class Lfo : public Oscillator {
public:
  // Constructor and destructor
  Lfo();
  ~Lfo();

  // Calculation of sine wave
  void tick(double samplerate);
};

#endif
