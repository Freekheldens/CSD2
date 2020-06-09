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
    envelope1Gui.setBounds(50, 80, 200, 200);
    envelope2Gui.setBounds(420, 80, 200, 200);
    fmGui.setBounds(280, 100, 90, 250);
    lfoGui.setBounds(30, 300, 600, 120);
    presetGui.setBounds(700, 100, 100, 20);
    reverbGui.setBounds(700, 180, 200, 150);
    masterGui.setBounds(700, 300, 200, 200);
}
