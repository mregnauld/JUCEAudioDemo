
#ifndef NativeLib_hpp
#define NativeLib_hpp

#include <stdio.h>
#include <string>
#include "Example.hpp"
#include "AudioPlayer.hpp"

class NativeLib
{
public:
	std::string nativeTest(std::string originalText);
	Example* nativeObjectTest(Example *example);
	void createPlayer();
	void deletePlayer();
	void nativePlay(double frequency);
	void nativeStop();
private:
	AudioPlayer* audioPlayer = nullptr;
};

#endif /* NativeLib_hpp */
