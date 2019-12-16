#include "amsynth.h"

Amsynth::Amsynth(){
  cout << "Addsynth constructor" << endl;
}

Amsynth::~Amsynth(){
  cout << "Addsynth destructor" << endl;
}

int Amsynth::makeSound(float baseFrequency){
  JackModule jack;
  jack.init();
  double samplerate = jack.getSamplerate();

    Sine osc1;
    Sine osc2;
    Saw env;

    osc1.setAmplitude(1);
    osc2.setAmplitude(1);
    env.setAmplitude(1);
    osc1.setFrequency(baseFrequency);
    osc2.setFrequency(0.25 * baseFrequency);
    env.setFrequency(0.5);

    //assign a function to the JackModule::onProces
    jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
       jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
         for(unsigned int i = 0; i < nframes; i++) {
           osc1.tick(samplerate);
           osc2.tick(samplerate);
           env.tick(samplerate);
           outBuf[i] = ((osc1.getSample() * ((osc2.getSample()+1)/2) / 2));
           outBuf[i] *= (1-((env.getSample() + 1) /2));
      }

      return 0;
    };

    jack.autoConnect();

    usleep(1900000);
    jack.end();

    return 0;
}
