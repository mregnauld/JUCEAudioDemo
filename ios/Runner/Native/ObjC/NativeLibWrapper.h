
#import <Foundation/Foundation.h>
#import "OCExample.h"

@interface NativeLibWrapper : NSObject

- (NSString*) nativeTest: (NSString*) originalText;

- (OCExample *) nativeObjectTest: (OCExample *) ocExample;

- (void) createPlayer;

- (void) deletePlayer;

- (void) nativePlay: (double) frequency;

- (void) nativeStop;

@end
