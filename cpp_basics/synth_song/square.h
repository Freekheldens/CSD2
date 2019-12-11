#include "oscillator.h"
#include <iostream>
using namespace std;

class Square : public Oscillator {
public:
  Square();
  ~Square();

  void tick(double samplerate);
};
