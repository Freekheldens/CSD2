#include "instrument.h"
using namespace std;

class Brass : public Instrument{
public:
  // constructor and destructor
  Brass(string type, string pitchRange);
  ~Brass();

  // methods
  void mute();
};
