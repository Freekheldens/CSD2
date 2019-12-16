#include "unistd.h"

#include "jack_module.h"

#include "square.h"
#include "saw.h"
#include <iostream>
using namespace std;

class Mixsynth {
public:
  // Constructor and destructor
  Mixsynth();
  ~Mixsynth();

  // Function that plays a sound at given frequency
  int makeSound(float baseFrequency);
};
