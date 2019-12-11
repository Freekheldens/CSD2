#ifndef _INS_H_
#define _INS_H_
#include <iostream>
using namespace std;

class Instrument{
public:
  // constructor destructor
  Instrument(string type, int pitchRange_low, int pitchRange_high);
  ~Instrument();

  // methods
  void play();
protected:
  string type;
  int pitchRange_low;
  int pitchRange_high;
  string sound;
};

#endif
