/*
  ==============================================================================

    PresetComponent.h
    Created: 9 Jun 2020 2:20:15pm
    Author:  Freek Heldens

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class PresetComponent    : public Component
{
public:
    PresetComponent();
    ~PresetComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PresetComponent)
    
    ComboBox presetMenu;
    Label presetLabel;
};
