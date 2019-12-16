#ifndef _SAW_H_
#define _SAW_H_

#include "oscillator.h"

#include <iostream>
using namespace std;

class Saw : public Oscillator {
public:
  // Constructor and destructor
  Saw();
  ~Saw();

  // Calculation of saw wave
  void tick(double samplerate);
};

#endif
