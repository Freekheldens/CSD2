#include "instrument.h"
using namespace std;

// constructor destructor
Instrument::Instrument(string type) {
  cout<<"Instrument::Instrument - constructor, type: " << type <<"\n";
  this->type = type;
}

Instrument::~Instrument(){
    cout<<"Instrument::Instrument - destructor, type: " << type <<"\n";
}

void Instrument::play(){
  cout<< type << " is playing\n";
}

void Instrument::pitch(string setPitch){
  cout<< type << " pitch is: "<< setPitch << "\n";
}
