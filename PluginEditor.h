#pragma once

#include "PluginProcessor.h"
#include "juce_audio_formats/juce_audio_formats.h"
#include "juce_audio_devices/juce_audio_devices.h"

enum TransportState {
    Stopped,
    Starting,
    Playing,
    Stopping
};

//==============================================================================
class AudioFilePlayerProcessorEditor  : public juce::AudioProcessorEditor,
                                        public juce::ChangeListener
{
public:
    explicit AudioFilePlayerProcessorEditor (AudioFilePlayerAudioProcessor&);
    ~AudioFilePlayerProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void changeState(TransportState newState);


private:
    juce::TextButton openButton;
    juce::TextButton playButton;
    juce::TextButton stopButton;

    std::unique_ptr<juce::FileChooser> chooser;

    juce::AudioFormatManager formatManager;
    std::unique_ptr<juce::AudioFormatReaderSource> readerSource;
    juce::AudioTransportSource transportSource;
    TransportState state;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioFilePlayerAudioProcessor& processorRef;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioFilePlayerProcessorEditor)
};