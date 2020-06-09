/*
  ==============================================================================

    LfoComponent.h
    Created: 9 Jun 2020 1:58:36pm
    Author:  Freek Heldens

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class LfoComponent    : public Component
{
public:
    LfoComponent();
    ~LfoComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LfoComponent)
    
    // parameters and labels for lfoControl
    Slider lfo1;
    Label lfo1Label;
    
    Slider lfo2;
    Label lfo2Label;
};
