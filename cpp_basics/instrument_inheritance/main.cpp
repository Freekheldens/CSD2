#include "flute.h"
#include "brass.h"

int main(){
  Flute flute1("Piccolo", "400 - 1000");
  Brass brass1("Horn", "100 - 600");
  flute1.play("fuuut!", "500");
  brass1.play("brrrrp", "200");
  brass1.mute();
  //end porgram
  return 0;
}
