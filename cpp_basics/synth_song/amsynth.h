#include "jack_module.h"
#include "unistd.h"
#include "sine.h"
#include "saw.h"
#include <iostream>
using namespace std;

class Amsynth {
public:
  Amsynth();
  ~Amsynth();

int argc;
char **argv;
int makeSound(float baseFrequency);
};
