#include "mixsynth.h"

// Constructor
Mixsynth::Mixsynth(){
}

// Destructor
Mixsynth::~Mixsynth(){
}

// Playing sound with a "mixed" oscillator synth
int Mixsynth::makeSound(float baseFrequency){
  JackModule jack;
  jack.init();
  double samplerate = jack.getSamplerate();

  // Making the oscillators and envelope
  Saw osc1;
  Square osc2;
  Saw env;

  // Setting the right values to oscillators and envelope
  osc1.setAmplitude(0.25);
  osc2.setAmplitude(0.25);
  env.setAmplitude(1);
  osc1.setFrequency(baseFrequency);
  osc2.setFrequency(0.252 * baseFrequency);
  env.setFrequency(0.5);

  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

       for(unsigned int i = 0; i < nframes; i++) {
          osc1.tick(samplerate);
          osc2.tick(samplerate);
          env.tick(samplerate);
          outBuf[i] = ((osc1.getSample() + osc2.getSample()) / 2);
          outBuf[i] *= (1-((env.getSample() + 1) /2));
      }

      return 0;
    };

    jack.autoConnect();
    // Wait untill envelope is finished to make next note
    usleep(1900000);
    jack.end();

    return 0;
}
