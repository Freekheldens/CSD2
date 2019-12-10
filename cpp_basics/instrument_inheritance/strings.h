#include "instrument.h"
using namespace std;

class Strings : public Instrument{
public:
  // constructor and destructor
  Strings(string type, int pitchRange_low, int pitchRange_high);
  ~Strings();

  // methods
  void bend();
};
