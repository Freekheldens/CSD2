#ifndef _SAW_LFO_H_
#define _SAW_LFO_H_

#include "oscillator.h"

#include <iostream>
using namespace std;

class Lfo_saw : public Oscillator {
public:
  // Constructor and destructor
  Lfo_saw();
  ~Lfo_saw();

  // Calculation of saw wave
  void tick(double samplerate);
};

#endif
