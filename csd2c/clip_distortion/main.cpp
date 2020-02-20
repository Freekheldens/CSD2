#include <iostream>
#include <thread>
#include "math.h"

#include "jack_module.h"
#include "sine.h"

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
  Sine sine1;
  sine1.setAmplitude(0.1);
  sine1.setFrequency(440);

  Sine lfo;
  lfo.setAmplitude(1);
  lfo.setFrequency(1);

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      sine1.tick(samplerate);
      lfo.tick(samplerate);

      float lfoSample = ((((lfo.getSample() * 0.5) + 0.5) * 10) + 5);
      outBuf[i] = sine1.getSample();

      float drive = lfoSample;

      //distortion method 1
      outBuf[i] = (outBuf[i] * drive);
      outBuf[i] = (2/M_PI) * atan(outBuf[i]);

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
