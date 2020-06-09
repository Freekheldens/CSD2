/*
  ==============================================================================

    MasterComponent.h
    Created: 9 Jun 2020 2:27:20pm
    Author:  Freek Heldens

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class MasterComponent    : public Component
{
public:
    MasterComponent();
    ~MasterComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterComponent)
    
    Slider masterVol;
    Label masterVolLabel;
};
