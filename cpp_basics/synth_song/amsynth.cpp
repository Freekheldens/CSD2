#include "amsynth.h"

Addsynth::Addsynth(){
  cout << "Addsynth constructor" << endl;
}

Addsynth::~Addsynth(){
  cout << "Addsynth destructor" << endl;
}

int Addsynth::makeSound(float baseFrequency){
  JackModule jack;
  jack.init();
  double samplerate = jack.getSamplerate();

    Sine osc1;
    Sine osc2;

    osc1.setAmplitude(1);
    osc2.setAmplitude(1);
    osc1.setFrequency(baseFrequency);
    osc2.setFrequency(0.25 * baseFrequency);

    //assign a function to the JackModule::onProces
    jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
       jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
         for(unsigned int i = 0; i < nframes; i++) {
           osc1.tick(samplerate);
           osc2.tick(samplerate);
           outBuf[i] = ((osc1.getSample() * ((osc2.getSample()+1)/2) / 2));
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
    return 0;
}
