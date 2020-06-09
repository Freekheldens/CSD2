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
    
    ratio.setRange(0, 100);
    ratio.setSliderStyle(Slider::SliderStyle::Rotary);
    ratio.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(ratio);
    
    ratioLabel.setText ("Ratio", dontSendNotification);
    ratioLabel.attachToComponent (&ratio, false);
    addAndMakeVisible(ratioLabel);
    
    depth.setRange(0, 100);
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
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background
}

void FmComponent::resized()
{
    
    ratio.setBounds(0, 0, 80, 80);
    depth.setBounds(0, 120, 80, 80);

}
