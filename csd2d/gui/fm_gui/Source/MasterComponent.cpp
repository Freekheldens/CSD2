/*
  ==============================================================================

    MasterComponent.cpp
    Created: 9 Jun 2020 2:27:20pm
    Author:  Freek Heldens

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MasterComponent.h"

//==============================================================================
MasterComponent::MasterComponent()
{
    
    masterVol.setRange(0, 100);
    masterVol.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    masterVol.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(masterVol);
    
    masterVolLabel.setText ("Master Volume", dontSendNotification);
    masterVolLabel.attachToComponent (&masterVol, false);
    addAndMakeVisible(masterVolLabel);
}

MasterComponent::~MasterComponent()
{
}

void MasterComponent::paint (Graphics& g)
{
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

}

void MasterComponent::resized()
{
    masterVol.setBounds(0, 20, 160, 50);
}
