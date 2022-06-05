#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioFilePlayerProcessorEditor::AudioFilePlayerProcessorEditor (AudioFilePlayerAudioProcessor& p)
    : AudioProcessorEditor (&p), processorRef (p)
{
    addAndMakeVisible(&openButton);
    openButton.setButtonText("Open file...");

    addAndMakeVisible(&playButton);
    playButton.setButtonText("Play");

    addAndMakeVisible(&stopButton);
    stopButton.setButtonText("Stop");


    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

AudioFilePlayerProcessorEditor::~AudioFilePlayerProcessorEditor()
{
}

//==============================================================================
void AudioFilePlayerProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void AudioFilePlayerProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
