# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)
project(JUCEAudioDemo)


# Optimisation compilateur debug
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Ofast")

# TODO JUCE
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

# TODO JUCE
# Oboe
set(OBOE_DIR "${CMAKE_SOURCE_DIR}/../../../../../JUCE/modules/juce_audio_devices/native/oboe")
add_subdirectory(${OBOE_DIR} ./oboe)

# CPU Features
add_library("cpufeatures" STATIC "${ANDROID_NDK}/sources/android/cpufeatures/cpu-features.c")

# JUCE
set(JuceAudio_DIR ${CMAKE_SOURCE_DIR}/src/main/cpp/juceaudio)
add_library(JuceAudio STATIC IMPORTED)
set_property(TARGET JuceAudio PROPERTY IMPORTED_LOCATION
        ${JuceAudio_DIR}/lib/${ANDROID_ABI}/libjuceaudio.a)
set_target_properties(JuceAudio PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
        ${JuceAudio_DIR}/lib/include)
include_directories(${JuceAudio_DIR}/lib/include)
include_directories(${CMAKE_SOURCE_DIR}/../../../../../JUCE/modules)



# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/main/cpp/native-lib.cpp
        src/main/cpp/AudioPlayer.cpp
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

# TODO JUCE
target_link_libraries( # Specifies the target library.
        native-lib

        JuceAudio

        "cpufeatures"
        "oboe"

        ${log-lib})