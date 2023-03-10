package com.juceaudio.juceaudiodemo

import android.os.Bundle
import android.util.Log
import io.flutter.embedding.android.FlutterActivity
import io.flutter.plugin.common.MethodChannel
import kotlin.random.Random

class MainActivity: FlutterActivity()
{
	
	private lateinit var methodChannel: MethodChannel
	private lateinit var nativeManager: NativeManager
	
	
	override fun onCreate(savedInstanceState: Bundle?)
	{
		super.onCreate(savedInstanceState)
		
		// player setup:
		nativeManager = NativeManager()
		nativeManager.setup()
		
		// commands received from Flutter code:
		val binaryMessenger = flutterEngine!!.dartExecutor.binaryMessenger
		methodChannel = MethodChannel(binaryMessenger, "method_channel")
		methodChannel.setMethodCallHandler { call, _ ->
			when (call.method)
			{
				"test" -> {
					val finalMessage = nativeManager.test("Message")
					Log.d("TAG", finalMessage)
				}
				"objectTest" -> {
					val exampleEntity = ExampleEntity()
					exampleEntity.testInt = 2
					exampleEntity.testFloat = 3F
					exampleEntity.testBoolean = false
					val finalExampleEntity = nativeManager.objectTest(exampleEntity)
					Log.d("TAG", finalExampleEntity.toString())
				}
				"playSound" -> {
					nativeManager.play(Random.nextDouble(100.0, 1001.0))
					Log.d("TAG", "onCreate: PLAY")
				}
				"stopSound" -> {
					nativeManager.stop()
					Log.d("TAG", "onCreate: STOP")
				}
				else -> {
					Log.e("TAG", "onCreate: ERROR")
				}
			}
		}
	}
	
}
