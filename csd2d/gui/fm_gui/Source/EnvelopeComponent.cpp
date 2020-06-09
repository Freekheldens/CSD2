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
    // making all the parameters needed for an ADSR envelope GUI
    attack.setRange(0, 100);
    attack.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attack.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(attack);
    
    attackLabel.setText ("Attack", dontSendNotification);
    attackLabel.attachToComponent (&attack, false);
    addAndMakeVisible(attackLabel);

    decay.setRange(0, 100);
    decay.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decay.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(decay);
    
    decayLabel.setText ("Decay", dontSendNotification);
    decayLabel.attachToComponent (&decay, false);
    addAndMakeVisible(decayLabel);
    
    sustain.setRange(0, 1);
    sustain.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustain.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(sustain);

    sustainLabel.setText ("Sustain", dontSendNotification);
    sustainLabel.attachToComponent (&sustain, false);
    addAndMakeVisible(sustainLabel);

    release.setRange(0, 100);
    release.setSliderStyle(Slider::SliderStyle::LinearVertical);
    release.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(release);

    releaseLabel.setText ("Release", dontSendNotification);
    releaseLabel.attachToComponent (&release, false);
    addAndMakeVisible(releaseLabel);
}

EnvelopeComponent::~EnvelopeComponent()
{
    
}

void EnvelopeComponent::paint (Graphics& g)
{

}

void EnvelopeComponent::resized()
{
    // setting borders and placement of the sliders
    int border = 50;
    
    attack.setBounds(0 + border, 0 + border, 50, 200);
    decay.setBounds(50 + border, 0 + border, 50, 200);
    sustain.setBounds(100 + border, 0 + border, 50, 200);
    release.setBounds(150 + border, 0 + border, 50, 200);
}
