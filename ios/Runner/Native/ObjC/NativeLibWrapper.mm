
#import <Foundation/Foundation.h>
#import "NativeLibWrapper.h"
#import "../Cpp/NativeLib.hpp"
#import "../Cpp/Example.hpp"

@interface NativeLibWrapper() {
	NativeLib nativeLib;
}
@end

@implementation NativeLibWrapper

- (NSString*) nativeTest: (NSString*) originalText {
	std::string finalText = nativeLib.nativeTest(
				   std::string([originalText UTF8String]));
	return [NSString stringWithUTF8String:finalText.c_str()];
}

- (OCExample *) nativeObjectTest: (OCExample *) ocExample {
	
	// mapping from Objective-C to C++:
	Example *example = new Example();
	example->testInt = ocExample.testInt;
	example->testBoolean = ocExample.testBoolean;
	example->testFloat = ocExample.testFloat;

	// calling the C++ function:
	Example *finalExample = nativeLib.nativeObjectTest(example);
	
	// mapping from C++ to Objective-C:
	OCExample *finalOCExample = [OCExample new];
	finalOCExample.testInt = finalExample->testInt;
	finalOCExample.testBoolean = finalExample->testBoolean;
	finalOCExample.testFloat = finalExample->testFloat;

	return finalOCExample;
}

- (void) createPlayer {
	nativeLib.createPlayer();
}

- (void) deletePlayer {
	nativeLib.deletePlayer();
}

- (void) nativePlay: (double) frequency {
	nativeLib.nativePlay(frequency);
}

- (void) nativeStop {
	nativeLib.nativeStop();
}

@end
