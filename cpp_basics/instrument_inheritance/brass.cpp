#include "brass.h"
using namespace std;

//constructor and destructor
Brass::Brass(string type) :
Instrument(type)
{
  pitchRange_low = 100;
  pitchRange_high = 400;
  sound = "Burrrrrp!";

  cout << "Brass added, type: " << type
  << ", with pitchrange: " << pitchRange_low << "Hz - " << pitchRange_high
  << "Hz" << endl <<"\n";
}
Brass::~Brass(){
}

// methods
void Brass::mute(){
  cout << type << " is muted" << endl <<"\n";
}
