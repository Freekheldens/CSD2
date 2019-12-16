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

int main(int argc,char **argv)
{
  Melodygen Mel;
  Mel.AMplay();
  //end the program
  return 0;
} // main()
