#include <iostream>
#include "instrument.h"
using namespace std;

int main(){
  Instrument instrument("ratata");
  instrument.play();
  Instrument instrument2("bambambam");
  instrument2.play();
  // end of main
  return 0;
}
