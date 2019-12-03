#include "brass.h"
using namespace std;

//constructor and destructor
Brass::Brass(string type, string pitchRange) : Instrument(type, pitchRange)
{
  //cout << "Brass::Brass - constructor, type: " << type << endl;
  cout << "Brass::Brass - constructor, type: " << type
  << ", with pitchrange: " << pitchRange << "Hz" << endl;
}
Brass::~Brass()
{
  cout << "Brass::Brass - destructor, type: "<< type << endl;
}

// methods
void Brass::mute(){
  cout << type << " is muted" << endl;
}
