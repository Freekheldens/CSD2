#include "instrument.h"
using namespace std;

class Brass : public Instrument{
public:
  // constructor and destructor
  Brass(string type, int pitchRange_low, int pitchRange_high);
  ~Brass();

  // methods
  void mute();
};
