
#pragma once

namespace jad
{

	class AudioSamplePlayerListener
	{
	protected:
		AudioSamplePlayerListener() = default;
		~AudioSamplePlayerListener() = default;
	public:
		virtual void prepareToPlay(int samplesPerBlock, double sampleRate) = 0;
		virtual void releaseResources() = 0;
		virtual float* getNextAudioSamples(int numberOfFrames, int numberOfOutputChannels) = 0;
	};

}
