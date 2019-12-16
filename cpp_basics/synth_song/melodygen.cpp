#include "melodygen.h"
#include "unistd.h"


Melodygen::Melodygen() {
}

Melodygen::~Melodygen() {
}

void Melodygen::AMplay(){

  Addsynth synht1;

  Saw env2;

  for (int i = 0; i < 3; i++){
    cout << i << endl;
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(1,2);
    float note;
    switch (dist(rng)) {
      case 1:
        note = 220;
        synht1.makeSound(220);
        break;
      case 2:
        note = 440;
        synht1.makeSound(440);
        break;
    }
    usleep(500000);
  }
}

void Melodygen::Mixplay(){
}
