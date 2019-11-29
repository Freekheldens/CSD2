#ifndef _INS_H_
#define _INS_H_
#include <iostream>
using namespace std;

class Instrument{
public:
  // constructor destructor
  Instrument(string type);
  ~Instrument();
  
  // methods
  void play();
  void pitch();
protected:
  string type;
};

#endif
