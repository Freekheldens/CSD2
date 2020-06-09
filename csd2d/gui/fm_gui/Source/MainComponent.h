/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "EnvelopeComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    
    //creating 2 instances of EnvelopeComponent
    EnvelopeComponent envelope1;
    EnvelopeComponent envelope2;
    
    
    Slider ratio;
    Label ratioLabel;

    Slider depth;
    Label depthLabel;
    
    Slider lfo1;
    Label lfo1Label;
    
    Slider lfo2;
    Label lfo2Label;
    
    ComboBox presetMenu;
    Label presetLabel;
    
    Slider reverbVol;
    Label reverbVolLabel;
    
    Slider revSize;
    Label revSizeLabel;
    
    Slider revTime;
    Label revTimeLabel;
    
    Slider revDamp;
    Label revDampLabel;
    
    Slider revDiff;
    Label revDiffLabel;
    
    Slider masterVol;
    Label masterVolLabel;
    
};
