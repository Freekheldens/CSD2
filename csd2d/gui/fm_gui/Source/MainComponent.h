/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "EnvelopeComponent.h"
#include "ReverbComponent.h"
#include "LfoComponent.h"
#include "FmComponent.h"
#include "PresetComponent.h"
#include "MasterComponent.h"

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
    
    // creating instances for all GUI's
    EnvelopeComponent envelope1Gui;
    EnvelopeComponent envelope2Gui;
    ReverbComponent reverbGui;
    LfoComponent lfoGui;
    FmComponent fmGui;
    PresetComponent presetGui;
    MasterComponent masterGui;
    
};
