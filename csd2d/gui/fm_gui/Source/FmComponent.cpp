/*
  ==============================================================================

    FmComponent.cpp
    Created: 9 Jun 2020 2:07:21pm
    Author:  Freek Heldens

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FmComponent.h"

//==============================================================================
FmComponent::FmComponent()
{
    // making all the parameters and labels needed for the fmControls GUI
    ratio.setRange(0, 100, 1);
    ratio.setSliderStyle(Slider::SliderStyle::Rotary);
    ratio.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(ratio);
    
    ratioLabel.setText ("Ratio", dontSendNotification);
    ratioLabel.attachToComponent (&ratio, false);
    addAndMakeVisible(ratioLabel);
    
    depth.setRange(0, 100, 1);
    depth.setSliderStyle(Slider::SliderStyle::Rotary);
    depth.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(depth);
    
    depthLabel.setText ("Depth", dontSendNotification);
    depthLabel.attachToComponent (&depth, false);
    addAndMakeVisible(depthLabel);
}

FmComponent::~FmComponent()
{
}

void FmComponent::paint (Graphics& g)
{
}

void FmComponent::resized()
{
    // making a layout for the rotary's
    ratio.setBounds(0, 20, 80, 80);
    depth.setBounds(0, 140, 80, 80);

}
