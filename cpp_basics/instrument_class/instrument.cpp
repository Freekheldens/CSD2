#include <iostream>
#include "instrument.h"
using namespace std;

Instrument::Instrument(string sound){
  this->sound = sound;
  cout<<"Instrument Constructor\n";
}

Instrument::~Instrument(){
  cout<<"Instrument Deconstructor\n";
}

string Instrument::play(){
  this->sound = sound;
  cout<< sound<<"\n";
  return sound;
}
