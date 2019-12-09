#include "instrument.h"
using namespace std;

class Strings : public Instrument{
public:
  // constructor and destructor
  Strings(string type, string pitchRange);
  ~Strings();

  // methods
  void bend();
};
