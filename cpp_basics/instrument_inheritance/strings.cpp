#include "strings.h"
using namespace std;

//constructor and destructor
Strings::Strings(string type) :
Instrument(type)
{
  pitchRange_low = 50;
  pitchRange_high = 500;
  sound = "Waowwww!";
  cout << "String added, type: " << type
  << ", with pitchrange: " << pitchRange_low << "Hz - " << pitchRange_high
  << "Hz" << endl <<"\n";
  sound = "Waoww!";
}
Strings::~Strings(){
}

// methods
void Strings::bend(){
  cout << type << " is bending" << endl <<"\n";
}
