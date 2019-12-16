#ifndef _SQU_H_
#define _SQU_H_

#include "oscillator.h"

#include <iostream>
using namespace std;

class Square : public Oscillator {
public:
  // Constructor and destructor
  Square();
  ~Square();

  // Calculation square wave
  void tick(double samplerate);
};

#endif
