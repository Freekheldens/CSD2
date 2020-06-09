/*
  ==============================================================================

    LfoComponent.cpp
    Created: 9 Jun 2020 1:58:36pm
    Author:  Freek Heldens

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LfoComponent.h"

//==============================================================================
LfoComponent::LfoComponent()
{
    
    lfo1.setRange(0, 100, 1);
    lfo1.setSliderStyle(Slider::SliderStyle::Rotary);
    lfo1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(lfo1);
    
    lfo1Label.setText ("Carrier LFO", dontSendNotification);
    lfo1Label.attachToComponent (&lfo1, true);
    addAndMakeVisible(lfo1Label);
    
    lfo2.setRange(0, 100, 1);
    lfo2.setSliderStyle(Slider::SliderStyle::Rotary);
    lfo2.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(lfo2);
    
    lfo2Label.setText ("Modulator LFO", dontSendNotification);
    lfo2Label.attachToComponent (&lfo2, true);
    addAndMakeVisible(lfo2Label);

}

LfoComponent::~LfoComponent()
{
}

void LfoComponent::paint (Graphics& g)
{
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background
}

void LfoComponent::resized()
{
    
    lfo1.setBounds(100, 30, 90, 90);
    lfo2.setBounds(480, 30, 90, 90);

}
