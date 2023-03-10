
#include "AudioPlayer.h"

AudioPlayer::AudioPlayer()
{
    audioSamplePlayer.setListener(this);
}

void AudioPlayer::prepareToPlay(int samplesPerBlock, double sampleRate)
{
    // sampleRate : number of frames per second
    deviceSampleRate = sampleRate;
}

void AudioPlayer::releaseResources()
{
    // release resources here if needed
}

float *AudioPlayer::getNextAudioSamples(int numberOfFrames, int numberOfOutputChannels)
{
    auto samples = new float[numberOfFrames * numberOfOutputChannels];
    int a;
    int b;
    double value;
    for (a = 0; a < numberOfFrames; a++)
    {
        for (b = 0; b < numberOfOutputChannels; b++)
        {
            value = sin(lastAngle + 2 * M_PI * a * soundFrequencyHz / deviceSampleRate);
            samples[a * numberOfOutputChannels + b] = (float) value;
        }
    }
    lastAngle = (lastAngle + 2 * M_PI * numberOfFrames * soundFrequencyHz / deviceSampleRate);

    // modulo, but with double:
    lastAngle = ((lastAngle / (2 * M_PI)) - floor(lastAngle / (2 * M_PI))) * 2 * M_PI;
    
    return samples;
}

void AudioPlayer::play(double frequency)
{
    if (!isPlayerActive)
    {
        isPlayerActive = true;
        audioSamplePlayer.setupPlayer();
    }
    soundFrequencyHz = frequency;
}

void AudioPlayer::stop()
{
    isPlayerActive = false;
    audioSamplePlayer.closePlayer();
}
