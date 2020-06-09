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
    
    addAndMakeVisible(envelope1Gui);
    addAndMakeVisible(envelope2Gui);
    addAndMakeVisible(reverbGui);
    addAndMakeVisible(lfoGui);
    addAndMakeVisible(fmGui);
    addAndMakeVisible(presetGui);
    addAndMakeVisible(masterGui);

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
    g.drawText("FM Control", 280, 50, 200, 100, Justification::topLeft);
    g.drawText("Modulator", 430, 50, 200, 100, Justification::topLeft);
    g.drawText("Reverb", 700, 140, 200, 100, Justification::topLeft);
}

void MainComponent::resized()
{
    // setting placment for all the GUI's
    envelope1Gui.setBounds(50, 80, 200, 220);
    envelope2Gui.setBounds(430, 80, 200, 220);
    fmGui.setBounds(280, 80, 90, 200);
    lfoGui.setBounds(50, 300, 580, 110);
    presetGui.setBounds(700, 80, 100, 40);
    reverbGui.setBounds(700, 170, 200, 170);
    masterGui.setBounds(700, 350, 160, 70);
}
