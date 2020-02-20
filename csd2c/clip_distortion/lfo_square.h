#ifndef _SQU_LFO_H_
#define _SQU_LFO_H_

#include "oscillator.h"

#include <iostream>
using namespace std;

class Lfo_square : public Oscillator {
public:
  // Constructor and destructor
  Lfo_square();
  ~Lfo_square();

  // Calculation square wave
  void tick(double samplerate);
};

#endif
