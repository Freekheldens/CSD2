/*
  ==============================================================================

    EnvelopeComponent.cpp
    Created: 8 Jun 2020 11:38:06pm
    Author:  Freek Heldens

  ==============================================================================
*/

#include <JuceHeader.h>
#include "EnvelopeComponent.h"

//==============================================================================
EnvelopeComponent::EnvelopeComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    attack.setRange(0, 100);
    attack.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attack.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(attack);
    
    addAndMakeVisible(attackLabel);
    attackLabel.setText ("Attack", dontSendNotification);
    attackLabel.attachToComponent (&attack, false);

    decay.setRange(0, 100);
    decay.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decay.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(decay);
    
    addAndMakeVisible(decayLabel);
    decayLabel.setText ("Decay", dontSendNotification);
    decayLabel.attachToComponent (&decay, false);
    
    sustain.setRange(0, 1);
    sustain.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustain.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(sustain);

    addAndMakeVisible(sustainLabel);
    sustainLabel.setText ("Sustain", dontSendNotification);
    sustainLabel.attachToComponent (&sustain, false);

    release.setRange(0, 100);
    release.setSliderStyle(Slider::SliderStyle::LinearVertical);
    release.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(release);

    addAndMakeVisible(releaseLabel);
    releaseLabel.setText ("Release", dontSendNotification);
    releaseLabel.attachToComponent (&release, false);
}

EnvelopeComponent::~EnvelopeComponent()
{
}

void EnvelopeComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
}

void EnvelopeComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    int border = 50;
    
    attack.setBounds(0 + border, 0 + border, 50, 200);
    decay.setBounds(50 + border, 0 + border, 50, 200);
    sustain.setBounds(100 + border, 0 + border, 50, 200);
    release.setBounds(150 + border, 0 + border, 50, 200);
}
