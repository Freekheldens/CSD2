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
  cout << "\n\n\nWelcome!\n\n\n";
  cout << "Please choose a synthesizer\n\nEnter a '1' for a AM-Synth\n";
  cout << "Or enter a '2' for a Mix-Synth (square wave and saw wave mixed)\n\n";
  int synthChoice;
  cin >> synthChoice;
  int noteAmount;
  cout << "\nPlease enter the number of notes you want to play: \n\n";
  cin >> noteAmount;
  Melodygen Mel;
  Mel.AMplay(noteAmount);
  //end the program
  return 0;
} // main()
