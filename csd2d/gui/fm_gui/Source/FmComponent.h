/*
  ==============================================================================

    FmComponent.h
    Created: 9 Jun 2020 2:07:21pm
    Author:  Freek Heldens

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class FmComponent    : public Component
{
public:
    FmComponent();
    ~FmComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FmComponent)

    Slider ratio;
    Label ratioLabel;

    Slider depth;
    Label depthLabel;
};
