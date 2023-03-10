package com.juceaudio.juceaudiodemo

class NativeManager
{
	
	companion object
	{
		// Accès NDK :
		init
		{
			// le try/catch est nécessaire pour mocker la classe pour les tests unitaires :
			try
			{
				System.loadLibrary("native-lib")
			}
			catch (_: UnsatisfiedLinkError) {}
		}
		
		// Fonctions NDK :
		@JvmStatic private external fun nativeTest(originalText: String): String
		@JvmStatic private external fun nativeObjectTest(exampleEntity: ExampleEntity): ExampleEntity
		@JvmStatic private external fun createPlayer(): Long
		@JvmStatic private external fun deletePlayer(audioPlayerHandle: Long)
		@JvmStatic private external fun nativePlay(audioPlayerHandle: Long, frequency: Double)
		@JvmStatic private external fun nativeStop(audioPlayerHandle: Long)
	}
	
	private var audioPlayerHandle: Long = 0
	
	
	fun test(originalText: String): String = nativeTest(originalText)
	fun objectTest(exampleEntity: ExampleEntity): ExampleEntity = nativeObjectTest(exampleEntity)
	
	fun setup()
	{
		if (audioPlayerHandle == 0L)
		{
			audioPlayerHandle = createPlayer()
		}
	}
	
	fun dispose()
	{
		if (audioPlayerHandle != 0L)
		{
			deletePlayer(audioPlayerHandle)
		}
		audioPlayerHandle = 0L
	}
	
	fun play(frequency: Double)
	{
		if (audioPlayerHandle != 0L)
		{
			nativePlay(audioPlayerHandle, frequency)
		}
	}
	
	fun stop()
	{
		if (audioPlayerHandle != 0L)
		{
			nativeStop(audioPlayerHandle)
		}
	}
	
}