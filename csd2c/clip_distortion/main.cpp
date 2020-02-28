#include <iostream>
#include <thread>
#include "math.h"

#include "jack_module.h"
#include "sine.h"
#include "lfo_sine.h"
#include "distortion.h"

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

  // distortions for both audio channels
  Distortion distL;
  Distortion distR;

  // lfo's for left and right audio channels
  Lfo_sine lfoR;
  Lfo_sine lfoL;

  // setting lfo speed for the right audio channel
  float lfoSpeedR = 1;
  lfoR.setFrequency(lfoSpeedR);

  // setting lfo speed for the left audio channel
  float lfoSpeedL = 2;
  lfoL.setFrequency(lfoSpeedL);

  // setting the lfo depth (this is for both left and right audio channels)
  float lfoDepth = 9;

  // amount of "drive" for distortion (also for both left and right audio channels)
  float driveAmount = 1;

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBufL, jack_default_audio_sample_t *outBufR, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // ticking sine and lfo's
      sine1.tick(samplerate);
      lfoL.tick(samplerate);
      lfoR.tick(samplerate);

      // left channel drive with lfo modulation
      float driveL = ((lfoL.getSample() * lfoDepth) + driveAmount);

      //right channel drive with lfo modulation
      float driveR = ((lfoR.getSample() * lfoDepth) + driveAmount);

      // distorting sine1 with distL and distR (this could also be inBuf[i] isntead of sine)
      outBufL[i] = (distL.getSample((sine1.getSample() * driveL))) / driveL;
      outBufR[i] = (distR.getSample((sine1.getSample() * driveR))) / driveR;

    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  cout << "\n\nPress 'q' when you want to quit the program.\n";
  cout << "Press 'r' to change the right lfo speed.\n";
  cout << "Press 'l' to change the left lfo speed.\n";
  cout << "Press 'd' to change the lfo depth.\n";
  cout << "Press 'a' to change the drive amount/lfo offset.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
      case 'r':
        float newlfoSpeedR;
        cin >> newlfoSpeedR;
        lfoR.setFrequency(newlfoSpeedR);
        break;
      case 'l':
        float newlfoSpeedL;
        cin >> newlfoSpeedL;
        lfoL.setFrequency(newlfoSpeedL);
        break;
      case 'd':
        cin >> lfoDepth;
        break;
      case 'a':
        cin >> driveAmount;
        break;
    }
  }

  //end the program
  return 0;
} // main()
