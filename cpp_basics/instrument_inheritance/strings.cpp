#include "strings.h"
using namespace std;

//constructor and destructor
Strings::Strings(string type, int pitchRange_low, int pitchRange_high) : Instrument(type, pitchRange_low, pitchRange_high)
{
  cout << "String added, type: " << type
  << ", with pitchrange: " << pitchRange_low << "Hz - " << pitchRange_high << "Hz" << endl <<"\n";
}
Strings::~Strings(){
}

// methods
void Strings::bend(){
  cout << type << " is bending" << endl <<"\n";
}
