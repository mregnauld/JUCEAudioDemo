
#include <jni.h>
#include <new>
#include <string>
#include <android/log.h>
#include <JuceHeader.h>
#include "AudioPlayer.h"
#include "Example.h"

extern "C" JNIEXPORT jstring JNICALL Java_com_juceaudio_juceaudiodemo_NativeManager_nativeTest(
        JNIEnv *env, jclass, jstring originalText)
{
    const char *cOriginalText = env->GetStringUTFChars(originalText, JNI_FALSE);
    std::string sOriginalText(cOriginalText);
    env->ReleaseStringUTFChars(originalText, cOriginalText);

    std::string sFinalText = sOriginalText + " " + sOriginalText;
    return env->NewStringUTF(sFinalText.c_str());
}

extern "C" JNIEXPORT jobject JNICALL Java_com_juceaudio_juceaudiodemo_NativeManager_nativeObjectTest(
        JNIEnv *env, jclass, jobject exampleEntity)
{
    // mapping from Kotlin to C++:
    auto *example = new Example();
    jclass exampleEntityClass = (*env).GetObjectClass(exampleEntity);
    
    jfieldID jTestInt = (*env).GetFieldID(exampleEntityClass, "testInt", "I");
    example->testInt = (*env).GetIntField(exampleEntity, jTestInt);
    jfieldID jTestFloat = (*env).GetFieldID(exampleEntityClass, "testFloat", "F");
    example->testFloat = (*env).GetFloatField(exampleEntity, jTestFloat);
    jfieldID jTestBoolean = (*env).GetFieldID(exampleEntityClass, "testBoolean", "Z");
    example->testBoolean = (*env).GetBooleanField(exampleEntity, jTestBoolean);
    
    // some dummy work:
    example->testInt *= 2;
    example->testFloat *= 3;
    example->testBoolean = !example->testBoolean;
    
    // mapping back from C++ to Kotlin:
    jclass exampleEntityFinalClass = (*env).FindClass("com/juceaudio/juceaudiodemo/ExampleEntity");
    jmethodID methodId = (*env).GetMethodID(exampleEntityFinalClass, "<init>", "()V");
    jobject jExampleEntity = (*env).NewObject(exampleEntityFinalClass, methodId);

    jfieldID testIntField = (*env).GetFieldID(exampleEntityFinalClass, "testInt", "I");
    (*env).SetIntField(jExampleEntity, testIntField, example->testInt);
    jfieldID testFloatField = (*env).GetFieldID(exampleEntityFinalClass, "testFloat", "F");
    (*env).SetFloatField(jExampleEntity, testFloatField, example->testFloat);
    jfieldID testBooleanField = (*env).GetFieldID(exampleEntityFinalClass, "testBoolean", "Z");
    (*env).SetBooleanField(jExampleEntity, testBooleanField, (jboolean) example->testBoolean);

    return jExampleEntity;
}

extern "C" JNIEXPORT jlong JNICALL Java_com_juceaudio_juceaudiodemo_NativeManager_createPlayer(
        JNIEnv __unused *env, jclass)
{
    auto *audioPlayer = new(std::nothrow) AudioPlayer();
    auto audioPlayerHandle = reinterpret_cast<jlong>(audioPlayer);
    return audioPlayerHandle;
}

extern "C" JNIEXPORT void JNICALL Java_com_juceaudio_juceaudiodemo_NativeManager_deletePlayer(
        JNIEnv __unused *env, jclass, jlong audioPlayerHandle)
{
    delete reinterpret_cast<AudioPlayer *>(audioPlayerHandle);
}

extern "C" JNIEXPORT void JNICALL Java_com_juceaudio_juceaudiodemo_NativeManager_nativePlay(
        JNIEnv __unused *env, jclass, jlong audioPlayerHandle, jdouble frequency)
{
    auto *audioPlayer = reinterpret_cast<AudioPlayer *>(audioPlayerHandle);
    if (audioPlayer == nullptr)
    {
        __android_log_print(ANDROID_LOG_ERROR, "TAG", "Invalid audio player handle");
        return;
    }
    audioPlayer->play(frequency);
}

extern "C" JNIEXPORT void JNICALL Java_com_juceaudio_juceaudiodemo_NativeManager_nativeStop(
        JNIEnv __unused *env, jclass, jlong audioPlayerHandle)
{
    auto *audioPlayer = reinterpret_cast<AudioPlayer *>(audioPlayerHandle);
    if (audioPlayer == nullptr)
    {
        __android_log_print(ANDROID_LOG_ERROR, "TAG", "Invalid audio player handle");
        return;
    }
    audioPlayer->stop();
}
