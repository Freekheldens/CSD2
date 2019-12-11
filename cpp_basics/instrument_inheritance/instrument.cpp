#include "instrument.h"
using namespace std;

// constructor destructor
Instrument::Instrument(string type, int pitchRange_low, int pitchRange_high) {
  this->pitchRange_low = pitchRange_low;
  this->pitchRange_high = pitchRange_high;
  this->type = type;
}

Instrument::~Instrument(){
}

void Instrument::play(){
  cout << type << " is playing at pitch: "
  << rand() %(pitchRange_high - pitchRange_low) + pitchRange_low << "Hz"
  << ", " << sound << "\n" << endl;
}
