#include "flute.h"
#include "percussion.h"

int main(){
  Flute flute1("piccolo");
  flute1.play();
  flute1.pitch("600");
  Percussion perc1("drumkit");
  perc1.play();
  perc1.pitch("noise");
  //end porgram
  return 0;
}
