package com.juceaudio.juceaudiodemo

import androidx.annotation.Keep

@Keep
class ExampleEntity
{
	var testInt: Int = 0
	var testFloat: Float = 0F
	var testBoolean: Boolean = false
	
	
	override fun toString(): String
	{
		return """
			testInt: $testInt
			testFloat: $testFloat
			testBoolean: $testBoolean
		""".trimIndent()
	}
}