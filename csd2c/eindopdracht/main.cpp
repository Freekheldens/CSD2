#include <iostream>
#include <thread>
#include "math.h"

#include "jack_module.h"
#include "sine.h"
#include "lfo_sine.h"
#include "distortion.h"
#include "circBuffer.h"
#include "flanger.h"

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

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  // Flanger(samplerate,feedback,lfoFreq,lfoDepth)
  Flanger flanger(samplerate, 80, 1, 50);


  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBufL, jack_default_audio_sample_t *outBufR, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // ticking sine and lfo's
      sine1.tick(samplerate);
      lfoL.tick(samplerate);
      lfoR.tick(samplerate);

      // "flanging"  the input buffer"
      float flanged_input = flanger.getSample(inBuf[i]);

      // converting the input buffer from -1/1 0/1
      float mic_in = inBuf[i];
      float mic_abs = abs(mic_in);

      // parameters to be controlled by audio input
      flanger.setFeedback((mic_abs * 100) -20);
      flanger.setLfoFreq((mic_abs * 100) + 10);
      flanger.setLfoDepth((mic_abs * 100) + 20);
      lfoR.setFrequency((mic_abs * 8) + 3);
      lfoL.setFrequency((mic_abs * 10) + 2);
      float lfoDepth = (9);

      // left channel drive with lfo modulation
      float driveL = ((lfoL.getSample() * lfoDepth) + 1);

      //right channel drive with lfo modulation
      float driveR = ((lfoR.getSample() * lfoDepth) + 1);

      // distorting the "flanged_input" with distL and distR
      outBufL[i] = (distL.getSample((flanged_input * driveL)) / driveL);
      outBufR[i] = (distR.getSample((flanged_input * driveR)) / driveR);

    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running, q = quit
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
