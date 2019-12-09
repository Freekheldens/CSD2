#include "strings.h"
using namespace std;

//constructor and destructor
Strings::Strings(string type, string pitchRange) : Instrument(type, pitchRange)
{
  //cout << "Brass::Brass - constructor, type: " << type << endl;
  cout << "String::String - constructor, type: " << type
  << ", with pitchrange: " << pitchRange << "Hz" << endl;
}
Strings::~Strings()
{
  cout << "String::String - destructor, type: "<< type << endl;
}

// methods
void Strings::bend(){
  cout << type << " is bending" << endl;
}
