#include "amsynth.h"
#include "mixsynth.h"
#include <random>
#include <iostream>
using namespace std;

class Melodygen {
public:
  // constructor destructor
  Melodygen();
  ~Melodygen();

void AMplay(int noteAmount);
void Mixplay(int noteAmount);
};
