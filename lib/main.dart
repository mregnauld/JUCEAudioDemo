import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

void main() => runApp(const MyApp());

class MyApp extends StatelessWidget
{
  const MyApp({super.key});

  @override
  Widget build(BuildContext context)
  {
    return MaterialApp(
      title: "JUCE Audio Demo",
      theme: ThemeData(primarySwatch: Colors.orange),
      home: const MyHomePage(),
    );
  }
}

class MyHomePage extends StatefulWidget
{
  const MyHomePage({super.key});

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage>
{

  final _methodChannel = const MethodChannel("method_channel");


  @override
  Widget build(BuildContext context)
  {
    return Scaffold(
      appBar: AppBar(
        title: const Text("JUCE Audio Demo"),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            TextButton(
              onPressed: () => _methodChannel.invokeMethod("test"),
              child: const Text(
                "NDK STRING TEST",
                style: TextStyle(fontSize: 30),
              ),
            ),
            const SizedBox(height: 16),
            TextButton(
              onPressed: () => _methodChannel.invokeMethod("objectTest"),
              child: const Text(
                "NDK OBJECT TEST",
                style: TextStyle(fontSize: 30),
              ),
            ),
            const SizedBox(height: 16),
            TextButton(
              onPressed: () => _methodChannel.invokeMethod("playSound"),
              child: const Text(
                "JUCE PLAY",
                style: TextStyle(fontSize: 30),
              ),
            ),
            const SizedBox(height: 16),
            TextButton(
              onPressed: () => _methodChannel.invokeMethod("stopSound"),
              child: const Text(
                "JUCE STOP",
                style: TextStyle(fontSize: 30),
              ),
            ),
          ],
        ),
      ),
    );
  }

}
