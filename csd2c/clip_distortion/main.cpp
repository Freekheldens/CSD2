#include <iostream>
#include <thread>
#include "math.h"

#include "jack_module.h"
#include "sine.h"
#include "lfo_sine.h"
#include "distortion.h"
#include "osc.h"

using namespace std;

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define PI_2 6.28318530717959

// global variables, to be received via OSC
float oscLfoSpeedR;
float oscLfoSpeedL;
float oscLfoDepth;
float oscDrive;

// subclass OSC into a local class so we can provide our own callback
class localOSC : public OSC
{
  int realcallback(const char *path,const char *types,lo_arg **argv,int argc)
  {
  // osc "paramater" name
  string msgpath=path;
    // if osc "parameter" name is /oscLfoSpeedR
    if(!msgpath.compare("/oscLfoSpeedR")){
      oscLfoSpeedR = argv[0]->f;
    }
    // if osc "parameter" name is /oscLfoSpeedL
    if(!msgpath.compare("/oscLfoSpeedL")){
      oscLfoSpeedL = argv[0]->f;
    }
    // if osc "parameter" name is /oscLfoDepth
    if(!msgpath.compare("/oscLfoDepth")){
      oscLfoDepth = argv[0]->f;
    }
    // if osc "parameter" name is /oscDrive
    if(!msgpath.compare("/oscDrive")){
      oscDrive = argv[0]->f;
    }
    return 0;
  }
};

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

  // setting up OSC server
  localOSC osc;
  string serverport="10024";
  osc.init(serverport);
  osc.set_callback("/oscLfoSpeedR","f");
  osc.set_callback("/oscLfoSpeedL","f");
  osc.set_callback("/oscLfoDepth","f");
  osc.set_callback("/oscDrive","f");
  osc.start();
  cout << "Listening on port " << serverport << endl;

  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBufL, jack_default_audio_sample_t *outBufR, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // ticking sine and lfo's
      sine1.tick(samplerate);
      lfoL.tick(samplerate);
      lfoR.tick(samplerate);

      //variables received over OSC
      lfoR.setFrequency(oscLfoSpeedR);
      lfoL.setFrequency(oscLfoSpeedL);

      // left channel drive with lfo modulation
      float driveL = ((lfoL.getSample() * oscLfoDepth) + oscDrive);

      //right channel drive with lfo modulation
      float driveR = ((lfoR.getSample() * oscLfoDepth) + oscDrive);

      // distorting sine1 with distL and distR (this could also be inBuf[i] instead of sine)
      outBufL[i] = (distL.getSample((sine1.getSample() * driveL))) / driveL;
      outBufR[i] = (distR.getSample((sine1.getSample() * driveR))) / driveR;

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
