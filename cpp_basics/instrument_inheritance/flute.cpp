#include "flute.h"
using namespace std;

// constructor and destructor
Flute::Flute(string type, int pitchRange_low, int pitchRange_high) :
Instrument(type, pitchRange_low, pitchRange_high)
{
  cout << "Flute added, type: " << type
  << ", with pitchrange: " << pitchRange_low << "Hz - " << pitchRange_high
  << "Hz" << endl <<"\n";
  sound = "Fuuut!";
}

Flute::~Flute(){
}
