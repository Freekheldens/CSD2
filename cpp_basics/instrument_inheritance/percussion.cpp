#include "percussion.h"
using namespace std;

//constructor and destructor
Percussion::Percussion(string type) : Instrument(type)
{
  cout << "Percussion::Percussion - constructor, type: "
    << type << "\n";
}
Percussion::~Percussion()
{
  std::cout << "Percussion::Percussion - destructor, type: "
    << type << "\n";
}
