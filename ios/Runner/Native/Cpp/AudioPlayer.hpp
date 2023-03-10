
#ifndef AudioPlayer_hpp
#define AudioPlayer_hpp
#define M_PI 3.14159265358979323846

#include "Juce/AudioSamplePlayerListener.h"
#include "JUCE/AudioSamplePlayer.h"

class AudioPlayer : jad::AudioSamplePlayerListener
{
public:

	AudioPlayer();
	~AudioPlayer() = default;

	void prepareToPlay(int samplesPerBlock, double sampleRate) override;
	void releaseResources() override;
	float* getNextAudioSamples(int nombreSamples, int nombreCanaux) override;
	
	void play(double frequency);
	void stop();
	
private:

	jad::AudioSamplePlayer audioSamplePlayer;
	double deviceSampleRate = 0;
	bool isPlayerActive = false;
	double soundFrequencyHz = 0;
	double lastAngle = 0;

};

#endif /* AudioPlayer_hpp */
