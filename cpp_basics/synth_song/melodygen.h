#include "amsynth.h"
#include "mixsynth.h"
#include <random>
#include <iostream>
using namespace std;

class Melodygen {
public:
  // Constructor destructor
  Melodygen();
  ~Melodygen();

  // playing notes with given synth
  void AMplay(int noteAmount);
  void Mixplay(int noteAmount);
};
