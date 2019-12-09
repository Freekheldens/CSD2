#include "flute.h"
#include "brass.h"
#include "strings.h"

int main(){
  Flute flute1("Piccolo", "400 - 1000");
  Brass brass1("Horn", "100 - 600");
  Strings strings1("Cello", "50 - 500");
  flute1.play("fuuut!", "500");
  brass1.play("brrrrp!", "200");
  strings1.play("ghwww!", "75");
  strings1.bend();
  brass1.mute();
  //end porgram
  return 0;
}
