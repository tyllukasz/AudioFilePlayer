#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioFilePlayerProcessorEditor::AudioFilePlayerProcessorEditor (AudioFilePlayerAudioProcessor& p)
    : AudioProcessorEditor (&p), state(Stopped), processorRef (p)
{
    addAndMakeVisible(&openButton);
    openButton.setButtonText("Open file...");
    openButton.onClick = [this] { openButtonClicked(); };

    addAndMakeVisible(&playButton);
    playButton.setButtonText("Play");
    playButton.onClick = [this] { playButtonClicked(); };
    playButton.setColour(juce::TextButton::buttonColourId, juce::Colours::green);
    playButton.setEnabled(false);

    addAndMakeVisible(&stopButton);
    stopButton.setButtonText("Stop");
    stopButton.onClick = [this] { stopButtonClicked(); };
    stopButton.setColour(juce::TextButton::buttonColourId, juce::Colours::red);
    stopButton.setEnabled(false);


    juce::ignoreUnused (processorRef);
    setSize (200, 200);

    formatManager.registerBasicFormats();
    transportSource.addChangeListener(this);


}

AudioFilePlayerProcessorEditor::~AudioFilePlayerProcessorEditor()
{
}

//==============================================================================
void AudioFilePlayerProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void AudioFilePlayerProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor...
    int margin = 10;
    int button_height = (getHeight() - 4 * margin) / 3;
    int button_width = getWidth() - 2 * margin;
    openButton.setBounds(margin, margin, button_width, button_height);
    playButton.setBounds(margin, 2 * margin + button_height, button_width, button_height);
    stopButton.setBounds(margin, 3 * margin + 2 * button_height, button_width, button_height);
}

void AudioFilePlayerProcessorEditor::changeState(TransportState newState) {
    if (state != newState) {
        state = newState;

        switch (state) {
            case Stopped:
                stopButton.setEnabled(false);
                playButton.setEnabled(true);
                transportSource.setPosition(0.0);
                break;

            case Starting:
                playButton.setEnabled(false);
                transportSource.start();
                break;

            case Playing:
                stopButton.setEnabled(true);
                break;

            case Stopping:
                transportSource.stop();
                break;
        }
    }
}

void AudioFilePlayerProcessorEditor::changeListenerCallback(juce::ChangeBroadcaster *source) {
    if (source == &transportSource) {
        if (transportSource.isPlaying())
            changeState(Playing);
        else
            changeState(Stopped);
    }
}

void AudioFilePlayerProcessorEditor::openButtonClicked() {
    //...
}

void AudioFilePlayerProcessorEditor::playButtonClicked() {
    changeState(Starting);
}

void AudioFilePlayerProcessorEditor::stopButtonClicked() {
    changeState(Stopping);
}
