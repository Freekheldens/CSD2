/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (900, 450);
    
    getLookAndFeel().setColour (Slider::thumbColourId, Colours::limegreen);
    
    addAndMakeVisible(envelope1);
    addAndMakeVisible(envelope2);
    
    addAndMakeVisible(reverbControls);
    
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

    lfo1.setRange(0, 100);
    lfo1.setSliderStyle(Slider::SliderStyle::Rotary);
    lfo1.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(lfo1);
    
    lfo1Label.setText ("Carrier LFO", dontSendNotification);
    lfo1Label.attachToComponent (&lfo1, true);
    addAndMakeVisible(lfo1Label);
    
    lfo2.setRange(0, 100);
    lfo2.setSliderStyle(Slider::SliderStyle::Rotary);
    lfo2.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(lfo2);
    
    lfo2Label.setText ("Modulator LFO", dontSendNotification);
    lfo2Label.attachToComponent (&lfo2, true);
    addAndMakeVisible(lfo2Label);
    
    addAndMakeVisible(presetMenu);
    
    presetLabel.setText("Presets:", dontSendNotification);
    presetLabel.attachToComponent(&presetMenu, false);
    addAndMakeVisible(presetLabel);

    masterVol.setRange(0, 100);
    masterVol.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    masterVol.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(masterVol);
    
    masterVolLabel.setText ("Master Volume", dontSendNotification);
    masterVolLabel.attachToComponent (&masterVol, false);
    addAndMakeVisible(masterVolLabel);

}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // background colour
    g.fillAll(Colours::black);
    // setting font and text
    Font theFont("Futura", "Medium", 25);
    g.setFont(theFont);
    g.setColour (Colours::white);
    g.drawText("Carrier", 50, 50, 100, 100, Justification::topLeft);
    g.drawText("FM Control", 290, 50, 200, 100, Justification::topLeft);
    g.drawText("Modulator", 430, 50, 200, 100, Justification::topLeft);
    g.drawText("Reverb", 700, 140, 200, 100, Justification::topLeft);
}

void MainComponent::resized()
{
    // setting placment for the envelopes
    envelope1.setBounds(0, 50, 300, 300);
    envelope2.setBounds(380, 50, 300, 300);
    
    reverbControls.setBounds(650, 140, 250, 250);
    
    const int border = 50;

    ratio.setBounds(250 + border, 50 + border, 80, 80);
    depth.setBounds(250 + border, 170 + border, 80, 80);

    lfo1.setBounds(70 + border, 280 + border, 90, 90);
    lfo2.setBounds(440 + border, 280 + border, 90, 90);

    presetMenu.setBounds(650 + border, 50 + border, 100, 20);

    masterVol.setBounds(650 + border, 320 + border, 160, 50);
    
}
