#include <iostream>
#include "instrument.h"
using namespace std;

// constructor
Instrument::Instrument(string sound){
  this->sound = sound;
  cout<<"\nInstrument Constructor\n";
}

// destructor
Instrument::~Instrument(){
  cout<<"\nInstrument Deconstructor\n";
}

// play function which prints given string
string Instrument::play(){
  cout<<"\n" << sound<<"\n";
  return sound;
}
