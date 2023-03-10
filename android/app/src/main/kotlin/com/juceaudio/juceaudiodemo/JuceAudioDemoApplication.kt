package com.juceaudio.juceaudiodemo

import com.rmsl.juce.Java
import io.flutter.app.FlutterApplication

class JuceAudioDemoApplication : FlutterApplication()
{
	
	override fun onCreate()
	{
		super.onCreate()
		Java.initialiseJUCE(this)
	}
	
}