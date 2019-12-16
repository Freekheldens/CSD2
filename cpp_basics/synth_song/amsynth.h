#include "unistd.h"

#include "jack_module.h"
#include "sine.h"
#include "saw.h"

#include <iostream>
using namespace std;

class Amsynth {
public:
  // Constructor and destructor
  Amsynth();
  ~Amsynth();

  // Function that plays a sound at given frequency
  int makeSound(float baseFrequency);
};
