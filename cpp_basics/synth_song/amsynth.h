#include "jack_module.h"
#include "sine.h"
#include "square.h"
#include "saw.h"
#include <iostream>
using namespace std;

class Addsynth {
public:
  Addsynth();
  ~Addsynth();

int argc;
char **argv;
int makeSound(float baseFrequency);
};
