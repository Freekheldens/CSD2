/*
  ==============================================================================

    PresetComponent.cpp
    Created: 9 Jun 2020 2:20:15pm
    Author:  Freek Heldens

  ==============================================================================
*/

#include <JuceHeader.h>
#include "PresetComponent.h"

//==============================================================================
PresetComponent::PresetComponent()
{
    
    addAndMakeVisible(presetMenu);
    
    presetLabel.setText("Presets:", dontSendNotification);
    presetLabel.attachToComponent(&presetMenu, false);
    addAndMakeVisible(presetLabel);

    // add items to the combo-box
    presetMenu.addItem ("Test", 1);
    presetMenu.addItem ("Bleh", 2);
    presetMenu.addItem ("Bloop", 3);
}

PresetComponent::~PresetComponent()
{
}

void PresetComponent::paint (Graphics& g)
{
    //g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));   // clear the background

}

void PresetComponent::resized()
{
   presetMenu.setBounds(0, 0, 100, 20);
}
