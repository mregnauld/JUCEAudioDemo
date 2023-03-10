import UIKit
import Flutter

@UIApplicationMain
@objc class AppDelegate: FlutterAppDelegate
{
	
	private var nativeManager: NativeManager!
	
	
	override func application(
	  _ application: UIApplication,
	  didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?
	) -> Bool
	{
		// player setup:
		nativeManager = NativeManager()
		nativeManager.setup()
		
		// commands received from Flutter code:
		let controller: FlutterViewController = window?.rootViewController as! FlutterViewController
		let binaryMessenger: FlutterBinaryMessenger = controller.binaryMessenger
		let channel = FlutterMethodChannel(name: "method_channel", binaryMessenger: binaryMessenger)
		channel.setMethodCallHandler({ [self] (call: FlutterMethodCall, result: @escaping FlutterResult) -> Void in
			switch call.method {
				case "test":
					let finalMessage = self.nativeManager.test("Message bis")
					print(finalMessage)
				
				case "objectTest":
					let exampleEntity = ExampleEntity(testInt: 2, testBoolean: false, testFloat: 3)
					let finalExampleEntity = self.nativeManager.objectTest(exampleEntity: exampleEntity)
					print(finalExampleEntity.description)
					
				case "playSound":
					nativeManager.play(frequency: (drand48() * 901) + 100)
					print("PLAY")

				case "stopSound":
					nativeManager.stop()
					print("STOP")

				default:
					print("ERROR")
			}
		})
		
		GeneratedPluginRegistrant.register(with: self)
		return super.application(application, didFinishLaunchingWithOptions: launchOptions)
	}
}

