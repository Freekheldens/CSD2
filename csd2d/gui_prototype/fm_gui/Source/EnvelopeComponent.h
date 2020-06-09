/*
  ==============================================================================

    EnvelopeComponent.h
    Created: 8 Jun 2020 11:38:06pm
    Author:  Freek Heldens

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class EnvelopeComponent    : public Component
{
public:
    EnvelopeComponent();
    ~EnvelopeComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EnvelopeComponent)
    
    // parameters and labels for ADSR envelope
    Slider attack;
    Label attackLabel;
    
    Slider decay;
    Label decayLabel;
    
    Slider sustain;
    Label sustainLabel;
    
    Slider release;
    Label releaseLabel;
};
