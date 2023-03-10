
class ExampleEntity
{
	var testInt: Int = 0
	var testBoolean: Bool = false
	var testFloat: Float = 0.0
	
	init(testInt: Int,
		 testBoolean: Bool,
		 testFloat: Float)
	{
		self.testInt = testInt
		self.testBoolean = testBoolean
		self.testFloat = testFloat
	}
	
	public var description: String
	{
		return "testInt: \(testInt)\ntestBoolean: \(testBoolean)\ntestFloat: \(testFloat)"
	}
}
