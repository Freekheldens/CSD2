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
    
    // making the knobs green
    getLookAndFeel().setColour (Slider::thumbColourId, Colours::limegreen);
    
    // making all the GUI modules visable
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
    g.drawText("Carrier", 30, 40, 100, 100, Justification::topLeft);
    g.drawText("FM Control", 280, 40, 200, 100, Justification::topLeft);
    g.drawText("Modulator", 430, 40, 200, 100, Justification::topLeft);
    g.drawText("Reverb", 700, 100, 200, 100, Justification::topLeft);
    g.drawText("Voice 1", 8, 4, 200, 100, Justification::topLeft);
    
    // drawing white lines for borders
    g.setColour(Colours::white);
    g.fillRect(0, 0, 900, 5);
    g.fillRect(0, 0, 5, 450);
    g.fillRect(260, 30, 5, 450);
    g.fillRect(395, 30, 5, 450);
    g.fillRect(670, 30, 5, 450);
    g.fillRect(670, 90, 450, 5);
    g.fillRect(670, 320, 450, 5);
    g.fillRect(0, 445, 900, 5);
    g.fillRect(0, 30, 900, 5);
    g.fillRect(895, 0, 5, 450);
    g.fillRect(80, 0, 5, 30);
}

void MainComponent::resized()
{
    // setting placment for all the GUI's modules
    envelope1Gui.setBounds(30, 80, 200, 220);
    envelope2Gui.setBounds(430, 80, 200, 220);
    fmGui.setBounds(290, 80, 90, 230);
    lfoGui.setBounds(30, 300, 580, 120);
    presetGui.setBounds(700, 40, 100, 40);
    reverbGui.setBounds(700, 130, 200, 170);
    masterGui.setBounds(700, 350, 160, 70);
}
