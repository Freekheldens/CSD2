/*
  ==============================================================================

    ReverbComponent.h
    Created: 9 Jun 2020 1:34:54pm
    Author:  Freek Heldens

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class ReverbComponent    : public Component
{
public:
    ReverbComponent();
    ~ReverbComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbComponent)

    // parameters and labels for reverb controls
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
};
