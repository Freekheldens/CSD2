#include <iostream>
#include <thread>
#include "math.h"

#include "jack_module.h"
#include "sine.h"
#include "lfo_sine.h"
#include "lfo_square.h"
#include "lfo_saw.h"

using namespace std;

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // sine wave to be modulated by distortion
  Sine sine1;
  sine1.setAmplitude(1);
  sine1.setFrequency(110);

  // lfo for "drive" parameter and setting frequency and depth
  Lfo_sine lfoR;
  Lfo_sine lfoL;

  float lfoSpeedR = 5;
  cout << "\nPlease enter lfo speed for right audio channel:\n\n";
  cin >> lfoSpeedR;
  lfoR.setFrequency(lfoSpeedR);

  float lfoSpeedL = 5;
  cout << "\nPlease enter lfo speed for left audio channel:\n\n";
  cin >> lfoSpeedL;
  lfoL.setFrequency(lfoSpeedL);

  float lfoDepth = 5;
  cout << "\nPlease enter lfo depth:\n\n";
  cin >> lfoDepth;

  // amount of "drive" for distortion
  float driveAmount = 5;
  cout << "\nPlease enter drive amount:\n\n";
  cin >> driveAmount;

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBufL, jack_default_audio_sample_t *outBufR, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      sine1.tick(samplerate);
      lfoL.tick(samplerate);
      lfoR.tick(samplerate);
      outBufL[i] = sine1.getSample(); // could also be inBuf[i]
      outBufR[i] = sine1.getSample();

      // calculating lfoDepth and driveAmount and assging it to variable to use below
      // left channel drive
      double driveL = ((lfoL.getSample() * lfoDepth) + driveAmount);

      //right channel drive
      double driveR = ((lfoR.getSample() * lfoDepth) + driveAmount);

      //distortion method 1 left channel
      outBufL[i] = (outBufL[i] * driveL);
      outBufL[i] = (2/M_PI) * atan(outBufL[i]);
      outBufL[i] /= driveL;

      //distortion method 1 right channel
      outBufR[i] = (outBufR[i] * driveR);
      outBufR[i] = (2/M_PI) * atan(outBufR[i]);
      outBufR[i] /= driveR;

    // distortion method 2
    // static double treshold = 0.8;
    //   if (outBuf[i] >= 0) {
    //     outBuf[i] = fmin(outBuf[i], treshold);
    //   }
    //   else {
    //     outBuf[i] = fmax(outBuf[i], -treshold);
    //   }
    //   outBuf[i] /= treshold;
    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }

  //end the program
  return 0;
} // main()
