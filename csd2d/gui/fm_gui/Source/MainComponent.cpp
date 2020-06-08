/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    setSize (900, 600);
    addAndMakeVisible(envelope1);
    addAndMakeVisible(envelope2);
    
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
    envelope1.setBounds(0, 0, 400, 400);
    envelope2.setBounds(400, 0, 400, 400);
}
