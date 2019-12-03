#ifndef _INS_H_
#define _INS_H_
#include <iostream>
using namespace std;

class Instrument{
public:
  // constructor destructor
  Instrument(string type, string pitchRange);
  ~Instrument();

  // methods
  void play(string sound, string pitch);
protected:
  string type;
  string pitchRange;
  string sound;
  string pitch;
};

#endif
