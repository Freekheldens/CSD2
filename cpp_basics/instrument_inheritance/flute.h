#include "instrument.h"
using namespace std;

class Flute : public Instrument{
public:
  // constructor an d destructor
  Flute(string type, int pitchRange_low, int pitchRange_high);
  ~Flute();
};
