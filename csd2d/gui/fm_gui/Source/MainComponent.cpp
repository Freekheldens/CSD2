/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (1000, 600);
    addAndMakeVisible(envelope1);
    addAndMakeVisible(envelope2);
    
    
    ratio.setSliderStyle(Slider::SliderStyle::Rotary);
    ratio.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(ratio);
    
    ratioLabel.setText ("Ratio", dontSendNotification);
    ratioLabel.attachToComponent (&ratio, false);
    addAndMakeVisible(ratioLabel);
    
    depth.setSliderStyle(Slider::SliderStyle::Rotary);
    depth.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(depth);
    
    depthLabel.setText ("Depth", dontSendNotification);
    depthLabel.attachToComponent (&depth, false);
    addAndMakeVisible(depthLabel);

    lfo1.setSliderStyle(Slider::SliderStyle::Rotary);
    lfo1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(lfo1);
    
    lfo1Label.setText ("Carrier LFO", dontSendNotification);
    lfo1Label.attachToComponent (&lfo1, true);
    addAndMakeVisible(lfo1Label);
    
    lfo2.setSliderStyle(Slider::SliderStyle::Rotary);
    lfo2.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(lfo2);
    
    lfo2Label.setText ("Modulator LFO", dontSendNotification);
    lfo2Label.attachToComponent (&lfo2, true);
    addAndMakeVisible(lfo2Label);
    
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    g.fillAll(Colours::black);
}

void MainComponent::resized()
{
    // setting placment for the envelopes
    envelope1.setBounds(0, 50, 300, 300);
    envelope2.setBounds(500, 50, 300, 300);

    const int border = 50;

    ratio.setBounds(250 + border, 50 + border, 90, 90);
    depth.setBounds(350 + border, 50 + border, 90, 90);
    
    lfo1.setBounds(50 + border, 300 + border, 90, 90);
    lfo2.setBounds(550 + border, 300 + border, 90, 90);
    
}
