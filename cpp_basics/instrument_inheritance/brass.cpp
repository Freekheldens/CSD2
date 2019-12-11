#include "brass.h"
using namespace std;

//constructor and destructor
Brass::Brass(string type, int pitchRange_low, int pitchRange_high) :
Instrument(type, pitchRange_low, pitchRange_high)
{
  cout << "Brass added, type: " << type
  << ", with pitchrange: " << pitchRange_low << "Hz - " << pitchRange_high
  << "Hz" << endl <<"\n";
  sound = "Burrrp!";
}
Brass::~Brass(){
}

// methods
void Brass::mute(){
  cout << type << " is muted" << endl <<"\n";
}
