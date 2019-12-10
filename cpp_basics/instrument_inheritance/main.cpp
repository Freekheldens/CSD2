#include "flute.h"
#include "brass.h"
#include "strings.h"

int main(){

  Flute flute1("Piccolo", 200, 400);
  Brass brass1("Horn", 100, 300);
  Strings strings1("Cello", 50, 100);

  flute1.play();
  brass1.play();
  strings1.play();

  strings1.bend();
  brass1.mute();

  //end porgram
  return 0;
}
