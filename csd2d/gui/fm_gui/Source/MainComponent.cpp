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
    
    addAndMakeVisible(envelope1);
    addAndMakeVisible(envelope2);
    
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
    g.fillAll(Colours::black);
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

    const int border = 50;

    ratio.setBounds(250 + border, 50 + border, 80, 80);
    depth.setBounds(250 + border, 170 + border, 80, 80);
    
    lfo1.setBounds(70 + border, 280 + border, 90, 90);
    lfo2.setBounds(440 + border, 280 + border, 90, 90);
    
    presetMenu.setBounds(650 + border, 50 + border, 100, 20);
    
    reverbVol.setBounds(750 + border, 140 + border, 100, 140);
    revSize.setBounds(650 + border, 140 + border, 60, 60);
    revTime.setBounds(700 + border, 140 + border, 60, 60);
    revDamp.setBounds(650 + border, 220 + border, 60, 60);
    revDiff.setBounds(700 + border, 220 + border, 60, 60);
    
    masterVol.setBounds(650 + border, 320 + border, 160, 50);
    
}
