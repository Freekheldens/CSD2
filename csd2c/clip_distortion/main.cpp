#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"

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
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  //assign a function to the JackModule::onProces
  jack.onProcess = [samplerate](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    static float phase = 0;
    static float amplitude = 1;
    static float frequency = 220;

    static float drive = 10;

    // static double treshold = 0.8;

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = amplitude * sin(phase * PI_2 );
      phase += frequency / samplerate;

    // distortion 1
    //   if (outBuf[i] >= 0) {
    //     outBuf[i] = fmin(outBuf[i], treshold);
    //   }
    //   else {
    //     outBuf[i] = fmax(outBuf[i], -treshold);
    //   }
    //   outBuf[i] /= treshold;

    //distortion 2
    outBuf[i] = (outBuf[i] * drive);
    outBuf[i] = (2/M_PI) * atan(outBuf[i]);

    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
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
