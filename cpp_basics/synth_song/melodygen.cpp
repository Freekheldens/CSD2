#include "melodygen.h"


Melodygen::Melodygen() {
}

Melodygen::~Melodygen() {
}

void Melodygen::AMplay(int noteAmount){

  Amsynth synht1;

  for (int i = 0; i < noteAmount;){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(1,7);
    cout << i << endl;
    switch (dist(rng)) {
      case 1:
        synht1.makeSound(261.63); // c
        break;
      case 2:
        synht1.makeSound(311.13); // es
        break;
      case 3:
        synht1.makeSound(349.23); // f
        break;
      case 4:
        synht1.makeSound(369.99); // ges
        break;
      case 5:
        synht1.makeSound(392); // g
        break;
      case 6:
        synht1.makeSound(466.61); // bes
        break;
      case 7:
        synht1.makeSound(523.25); // c'
        break;
    }
    i++;
  }
}

void Melodygen::Mixplay(int noteAmount) {

  Mixsynth synht1;

  for (int i = 0; i < noteAmount;){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(1,7);
    cout << i << endl;
    switch (dist(rng)) {
      case 1:
        synht1.makeSound(261.63); // c
        break;
      case 2:
        synht1.makeSound(311.13); // es
        break;
      case 3:
        synht1.makeSound(349.23); // f
        break;
      case 4:
        synht1.makeSound(369.99); // ges
        break;
      case 5:
        synht1.makeSound(392); // g
        break;
      case 6:
        synht1.makeSound(466.61); // bes
        break;
      case 7:
        synht1.makeSound(523.25); // c'
        break;
    }
    i++;
  }
}
