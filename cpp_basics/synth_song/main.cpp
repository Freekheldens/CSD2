#include <iostream>
#include <thread>
#include "melodygen.h"
using namespace std;

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

int main()
{
  int noteAmount;
  Melodygen Mel;
  Melodygen Mel2;
  cout << "\n\n\nWelcome!\n\n\n";
  cout << "Please choose a synthesizer\n\nEnter a '1' for a AM-Synth\n";
  cout << "Or enter a '2' for a Mix-Synth (square wave and saw wave mixed)\n\n";
  switch (cin.get()) {
    case '1':
      cout << "\nPlease enter the number of notes you want to play: \n\n";
      cin >> noteAmount;
      cout << "\n";
      Mel.AMplay(noteAmount);
      break;
    case '2':
      cout << "\nPlease enter the number of notes you want to play: \n\n";
      cin >> noteAmount;
      cout << "\n";
      Mel2.Mixplay(noteAmount);
      break;
  }
  return 0;
} // main()
