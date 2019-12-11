#include "flute.h"
using namespace std;

// constructor and destructor
Flute::Flute(string type) :
Instrument(type)
{
  pitchRange_low = 200;
  pitchRange_high = 600;
  sound = "Fuuut!";

  cout << "Flute added, type: " << type
  << ", with pitchrange: " << pitchRange_low << "Hz - " << pitchRange_high
  << "Hz" << endl <<"\n";
}

Flute::~Flute(){
}
