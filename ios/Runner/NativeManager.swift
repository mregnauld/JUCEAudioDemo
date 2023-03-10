
class NativeManager
{
	private let nativeLibWrapper = NativeLibWrapper()
	
	func test(_ originalText: String) -> String
	{
		return nativeLibWrapper.nativeTest(originalText)
	}
	
	func objectTest(exampleEntity: ExampleEntity) -> ExampleEntity
	{
		// mapping from Swift to Objective-C:
		let ocExample = OCExample()
		ocExample.testInt = Int32(exampleEntity.testInt)
		ocExample.testFloat = exampleEntity.testFloat
		ocExample.testBoolean = exampleEntity.testBoolean
		
		let finalOCExample = nativeLibWrapper.nativeObjectTest(ocExample)

		// mapping from Objective-C to Swift:
		return ExampleEntity(
			testInt: Int(finalOCExample!.testInt),
			testBoolean: finalOCExample!.testBoolean,
			testFloat: finalOCExample!.testFloat)
	}
	
	func setup()
	{
		nativeLibWrapper.createPlayer()
	}
	
	func dispose()
	{
		nativeLibWrapper.deletePlayer()
	}
	
	func play(frequency: Double)
	{
		nativeLibWrapper.nativePlay(frequency)
	}
	
	func stop()
	{
		nativeLibWrapper.nativeStop()
	}
	
}
