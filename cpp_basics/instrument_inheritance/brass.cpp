#include "brass.h"
using namespace std;

//constructor and destructor
Brass::Brass(string type, string pitchRange) : Instrument(type, pitchRange)
{
  //cout << "Brass::Brass - constructor, type: " << type << endl;
  cout << "Brass added, type: " << type
  << ", with pitchrange: " << pitchRange << "Hz" << endl <<"\n";
}
Brass::~Brass(){
}

// methods
void Brass::mute(){
  cout << type << " is muted" << endl <<"\n";
}
