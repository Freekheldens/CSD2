#include "strings.h"
using namespace std;

//constructor and destructor
Strings::Strings(string type, string pitchRange) : Instrument(type, pitchRange)
{
  //cout << "Brass::Brass - constructor, type: " << type << endl;
  cout << "String added, type: " << type
  << ", with pitchrange: " << pitchRange << "Hz" << endl <<"\n";
}
Strings::~Strings(){
}

// methods
void Strings::bend(){
  cout << type << " is bending" << endl <<"\n";
}
