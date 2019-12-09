#include "instrument.h"
using namespace std;

// constructor destructor
Instrument::Instrument(string type, string pitchRange) {
  this->type = type;
}

Instrument::~Instrument(){
}

void Instrument::play(string sound, string pitch){
  cout << type << " is playing at pitch: " << pitch << "Hz" << ", " << sound
  << endl <<"\n";
}
