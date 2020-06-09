/*
  ==============================================================================

    ReverbComponent.cpp
    Created: 9 Jun 2020 1:34:54pm
    Author:  Freek Heldens

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ReverbComponent.h"

//==============================================================================
ReverbComponent::ReverbComponent()
{
    // making all the parameters needed for reverb control GUI
    reverbVol.setRange(0, 100);
    reverbVol.setSliderStyle(Slider::SliderStyle::LinearVertical);
    reverbVol.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(reverbVol);
    
    reverbVolLabel.setText ("Volume", dontSendNotification);
    reverbVolLabel.attachToComponent (&reverbVol, false);
    addAndMakeVisible(reverbVolLabel);

    revSize.setRange(0, 100);
    revSize.setSliderStyle(Slider::SliderStyle::Rotary);
    revSize.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(revSize);
    
    revSizeLabel.setText ("Size", dontSendNotification);
    revSizeLabel.attachToComponent (&revSize, false);
    addAndMakeVisible(revSizeLabel);
    
    revTime.setRange(0, 100);
    revTime.setSliderStyle(Slider::SliderStyle::Rotary);
    revTime.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(revTime);
    
    revTimeLabel.setText ("Time", dontSendNotification);
    revTimeLabel.attachToComponent (&revTime, false);
    addAndMakeVisible(revTimeLabel);

    revDamp.setRange(0, 100);
    revDamp.setSliderStyle(Slider::SliderStyle::Rotary);
    revDamp.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(revDamp);
    
    revDampLabel.setText ("Damp", dontSendNotification);
    revDampLabel.attachToComponent (&revDamp, false);
    addAndMakeVisible(revDampLabel);

    revDiff.setRange(0, 100);
    revDiff.setSliderStyle(Slider::SliderStyle::Rotary);
    revDiff.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(revDiff);
    
    revDiffLabel.setText ("Diff.", dontSendNotification);
    revDiffLabel.attachToComponent (&revDiff, false);
    addAndMakeVisible(revDiffLabel);

}

ReverbComponent::~ReverbComponent()
{
}

void ReverbComponent::paint (Graphics& g)
{
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background
}

void ReverbComponent::resized()
{
    
    reverbVol.setBounds(100, 0, 100, 140);
    revSize.setBounds(0, 0, 60, 60);
    revTime.setBounds(50, 0, 60, 60);
    revDamp.setBounds(0, 80, 60, 60);
    revDiff.setBounds(50, 80, 60, 60);

}
