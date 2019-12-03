#include "flute.h"
using namespace std;

// constructor and destructor
Flute::Flute(string type, string pitchRange) : Instrument(type, pitchRange)
{
  //cout << "Flute::Flute - constructor, type: " << type << endl;
  cout << "Flute::Flute - constructor, type: " << type
  << ", with pitchrange: " << pitchRange << "Hz" << endl;
}

Flute::~Flute()
{
  cout << "Flute::Flute - destructor, type: " << type << endl;
}
