#include "melodygen.h"

// Constructor
Melodygen::Melodygen() {
}

// Destructor
Melodygen::~Melodygen() {
}

// Playing random notes in a blues scale with the AM synth
void Melodygen::AMplay(int noteAmount){

  Amsynth synht1;

  // Looping untill noteAmount is reached
  for (int i = 0; i < noteAmount;){
    // Generating random number
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(1,7);
    switch (dist(rng)) {
      case 1:
        cout << "Note " << i+1 << ": C\n" << endl;
        synht1.makeSound(261.63); // c
        break;
      case 2:
        cout << "Note " << i+1 << ": Es\n" << endl;
        synht1.makeSound(311.13); // es
        break;
      case 3:
        cout << "Note " << i+1 << ": F\n" << endl;
        synht1.makeSound(349.23); // f
        break;
      case 4:
        cout << "Note " << i+1 << ": Ges\n" << endl;
        synht1.makeSound(369.99); // ges
        break;
      case 5:
        cout << "Note " << i+1 << ": G\n" << endl;
        synht1.makeSound(392); // g
        break;
      case 6:
        cout << "Note " << i+1 << ": Bes\n" << endl;
        synht1.makeSound(466.61); // bes
        break;
      case 7:
        cout << "Note " << i+1 << ": C'\n" << endl;
        synht1.makeSound(523.25); // c'
        break;
    }
    i++;
  }
}

// Playing random notes in a blues scale with the "Mix" synth
void Melodygen::Mixplay(int noteAmount) {

  Mixsynth synht2;

  // Looping untill noteAmount is reached
  for (int i = 0; i < noteAmount;){
    // Generating random number 
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(1,7);
    switch (dist(rng)) {
      case 1:
        cout << "Note " << i+1 << ": C\n" << endl;
        synht2.makeSound(261.63); // c
        break;
      case 2:
        cout << "Note " << i+1 << ": Es\n" << endl;
        synht2.makeSound(311.13); // es
        break;
      case 3:
        cout << "Note " << i+1 << ": F\n" << endl;
        synht2.makeSound(349.23); // f
        break;
      case 4:
        cout << "Note " << i+1 << ": Ges\n" << endl;
        synht2.makeSound(369.99); // ges
        break;
      case 5:
        cout << "Note " << i+1 << ": G\n" << endl;
        synht2.makeSound(392); // g
        break;
      case 6:
        cout << "Note " << i+1 << ": Bes\n" << endl;
        synht2.makeSound(466.61); // bes
        break;
      case 7:
        cout << "Note " << i+1 << ": C'\n" << endl;
        synht2.makeSound(523.25); // c'
        break;
    }
    i++;
  }
}
