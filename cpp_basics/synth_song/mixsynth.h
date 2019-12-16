#include "jack_module.h"
#include "square.h"
#include "saw.h"
#include <iostream>
using namespace std;

class Mixsynth {
public:
  Mixsynth();
  ~Mixsynth();

int argc;
char **argv;
int makeSound(float baseFrequency);
};
