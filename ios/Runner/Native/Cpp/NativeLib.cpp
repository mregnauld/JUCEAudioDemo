
#include "NativeLib.hpp"

std::string NativeLib::nativeTest(std::string originalText)
{
	return originalText + " " + originalText;
}

Example* NativeLib::nativeObjectTest(Example *example)
{
	// some dummy work:
	example->testInt *= 2;
	example->testFloat *= 3;
	example->testBoolean = !example->testBoolean;
	return example;
}

void NativeLib::createPlayer()
{
	audioPlayer = new AudioPlayer();
}

void NativeLib::deletePlayer()
{
	if (audioPlayer != nullptr)
	{
		delete audioPlayer;
	}
}

void NativeLib::nativePlay(double frequency)
{
	if (audioPlayer != nullptr)
	{
		audioPlayer->play(frequency);
	}
}

void NativeLib::nativeStop()
{
	if (audioPlayer != nullptr)
	{
		audioPlayer->stop();
	}
}

