
cmake_minimum_required(VERSION 3.18.1)
project(JUCEAudioDemo)


# optimization
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Ofast")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

# User directory
set(USER_HOME_DIR $ENV{HOME})

# Oboe
set(OBOE_DIR "${USER_HOME_DIR}/JUCE/modules/juce_audio_devices/native/oboe")
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
include_directories(${USER_HOME_DIR}/JUCE/modules)


add_library( # Sets the name of the library.
        native-lib

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        src/main/cpp/native-lib.cpp
        src/main/cpp/AudioPlayer.cpp
        )

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

target_link_libraries( # Specifies the target library.
        native-lib

        JuceAudio

        "cpufeatures"
        "oboe"

        ${log-lib})