#include "flute.h"
using namespace std;

//constructor and destructor
Flute::Flute(string type) : Instrument(type)
{
  cout << "Flute::Flute - constructor, type: "
    << type << "\n";
}
Flute::~Flute()
{
  std::cout << "Flute::Flute - destructor, type: "
    << type << "\n";
}
