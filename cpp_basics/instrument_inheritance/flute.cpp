#include "flute.h"
using namespace std;

// constructor and destructor
Flute::Flute(string type, string pitchRange) : Instrument(type, pitchRange)
{
  //cout << "Flute::Flute - constructor, type: " << type << endl;
  cout << "Flute added, type: " << type
  << ", with pitchrange: " << pitchRange << "Hz" << endl <<"\n";
}

Flute::~Flute(){
}
