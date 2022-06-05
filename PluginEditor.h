#pragma once

#include "PluginProcessor.h"

//==============================================================================
class AudioFilePlayerProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    explicit AudioFilePlayerProcessorEditor (AudioFilePlayerAudioProcessor&);
    ~AudioFilePlayerProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::TextButton openButton;
    juce::TextButton playButton;
    juce::TextButton stopButton;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioFilePlayerAudioProcessor& processorRef;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioFilePlayerProcessorEditor)
};
