#include <iostream>
using namespace std;

class instrument
{
public:
  instrument() //construcor
  {
    sound = "ratata"; //default "sound"
  }
  int set_sound(string new_sound) //changing sound to input from main
  {
    sound = new_sound;
  }
  int play()
  {
    std::cout << sound << std::endl;
  }
  string sound;
};





int main()
{
  instrument ins1;
  instrument ins2;

  ins1.play();
  ins2.set_sound("bambambam");
  ins2.play();

  return 0;
}
