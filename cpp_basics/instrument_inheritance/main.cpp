#include "flute.h"
#include "brass.h"
#include "strings.h"

int main(){

  Flute flute1("Piccolo");
  Brass brass1("Horn");
  Brass brass2("Trombone");
  Strings strings1("Cello");

  flute1.play();
  brass1.play();
  brass2.play();
  strings1.play();

  strings1.bend();
  brass1.mute();

  //end porgram
  return 0;
}
