#include "oscillator.h"
#include <iostream>
using namespace std;

class Sine : public Oscillator {
public:
  Sine();
  ~Sine();

  void tick(double samplerate);
};
