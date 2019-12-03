#include "instrument.h"
using namespace std;

// constructor destructor
Instrument::Instrument(string type, string pitchRange) {
  cout << "Instrument::Instrument - constructor, type: " << type << endl;
  this->type = type;
}

Instrument::~Instrument(){
  cout << "Instrument::Instrument - destructor, type: " << type << endl;
}

void Instrument::play(string sound, string pitch){
  cout << type << " is playing at pitch: " << pitch << "Hz" << ", " << sound
  << endl;
}
