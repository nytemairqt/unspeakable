/*

    IMPORTANT! This file is auto-generated each time you save your
    project - if you alter its contents, your changes may be overwritten!

    There's a section below where you can add your own custom code safely, and the
    Projucer will preserve the contents of that block, but the best way to change
    any of these definitions is by using the Projucer's project settings.

    Any commented-out settings will assume their default values.

*/

#pragma once

//==============================================================================
// [BEGIN_USER_CODE_SECTION]

// (You can add your own code in this section, and the Projucer will not overwrite it)

// [END_USER_CODE_SECTION]

/*
  ==============================================================================

   In accordance with the terms of the JUCE 6 End-Use License Agreement, the
   JUCE Code in SECTION A cannot be removed, changed or otherwise rendered
   ineffective unless you have a JUCE Indie or Pro license, or are using JUCE
   under the GPL v3 license.

   End User License Agreement: www.juce.com/juce-6-licence

  ==============================================================================
*/

// BEGIN SECTION A

#ifndef JUCE_DISPLAY_SPLASH_SCREEN
 #define JUCE_DISPLAY_SPLASH_SCREEN 0
#endif

// END SECTION A

#define JUCE_USE_DARK_SPLASH_SCREEN 1

#define JUCE_PROJUCER_VERSION 0x60103

//==============================================================================
#define JUCE_MODULE_AVAILABLE_hi_dsp_library            1
#define JUCE_MODULE_AVAILABLE_hi_faust                  1
#define JUCE_MODULE_AVAILABLE_hi_faust_types            1
#define JUCE_MODULE_AVAILABLE_hi_tools                  1
#define JUCE_MODULE_AVAILABLE_juce_audio_basics         1
#define JUCE_MODULE_AVAILABLE_juce_audio_formats        1
#define JUCE_MODULE_AVAILABLE_juce_core                 1
#define JUCE_MODULE_AVAILABLE_juce_data_structures      1
#define JUCE_MODULE_AVAILABLE_juce_dsp                  1
#define JUCE_MODULE_AVAILABLE_juce_events               1
#define JUCE_MODULE_AVAILABLE_juce_graphics             1
#define JUCE_MODULE_AVAILABLE_juce_gui_basics           1

#define JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED 1

//==============================================================================
// hi_dsp_library flags:

#ifndef    HI_EXPORT_AS_PROJECT_DLL
 #define   HI_EXPORT_AS_PROJECT_DLL 1
#endif

#ifndef    HI_EXPORT_DSP_LIBRARY
 #define   HI_EXPORT_DSP_LIBRARY 0
#endif

#ifndef    HISE_UPDATE_CONVOLUTION_DAMPING_ASYNC
 //#define HISE_UPDATE_CONVOLUTION_DAMPING_ASYNC 1
#endif

#ifndef    IS_STATIC_DSP_LIBRARY
 #define   IS_STATIC_DSP_LIBRARY 0
#endif

#ifndef    HISE_LOG_FILTER_FREQMOD
 //#define HISE_LOG_FILTER_FREQMOD 0
#endif

//==============================================================================
// hi_faust flags:

#ifndef    HISE_INCLUDE_FAUST
 #define   HISE_INCLUDE_FAUST 0
#endif

#ifndef    HISE_FAUST_USE_LLVM_JIT
 //#define HISE_FAUST_USE_LLVM_JIT 1
#endif

#ifndef    HISE_INCLUDE_FAUST_JIT
 //#define HISE_INCLUDE_FAUST_JIT 0
#endif

//==============================================================================
// hi_faust_types flags:

#ifndef    FAUST_NO_WARNING_MESSAGES
 //#define FAUST_NO_WARNING_MESSAGES 0
#endif

//==============================================================================
// hi_tools flags:

#ifndef    HISE_NO_GUI_TOOLS
 #define   HISE_NO_GUI_TOOLS 1
#endif

#ifndef    HISE_USE_NEW_CODE_EDITOR
 //#define HISE_USE_NEW_CODE_EDITOR 1
#endif

#ifndef    IS_MARKDOWN_EDITOR
 //#define IS_MARKDOWN_EDITOR 0
#endif

#ifndef    HISE_INCLUDE_PITCH_DETECTION
 //#define HISE_INCLUDE_PITCH_DETECTION 1
#endif

#ifndef    HISE_INCLUDE_RT_NEURAL
 //#define HISE_INCLUDE_RT_NEURAL 1
#endif

#ifndef    HISE_USE_EXTENDED_TEMPO_VALUES
 //#define HISE_USE_EXTENDED_TEMPO_VALUES 0
#endif

//==============================================================================
// juce_audio_formats flags:

#ifndef    JUCE_USE_FLAC
 //#define JUCE_USE_FLAC 1
#endif

#ifndef    JUCE_USE_OGGVORBIS
 //#define JUCE_USE_OGGVORBIS 1
#endif

#ifndef    JUCE_USE_MP3AUDIOFORMAT
 //#define JUCE_USE_MP3AUDIOFORMAT 0
#endif

#ifndef    JUCE_USE_LAME_AUDIO_FORMAT
 //#define JUCE_USE_LAME_AUDIO_FORMAT 0
#endif

#ifndef    JUCE_USE_WINDOWS_MEDIA_FORMAT
 //#define JUCE_USE_WINDOWS_MEDIA_FORMAT 1
#endif

//==============================================================================
// juce_core flags:

#ifndef    JUCE_FORCE_DEBUG
 //#define JUCE_FORCE_DEBUG 0
#endif

#ifndef    JUCE_ENABLE_AUDIO_GUARD
 //#define JUCE_ENABLE_AUDIO_GUARD 0
#endif

#ifndef    JUCE_LOG_ASSERTIONS
 //#define JUCE_LOG_ASSERTIONS 0
#endif

#ifndef    JUCE_CHECK_MEMORY_LEAKS
 //#define JUCE_CHECK_MEMORY_LEAKS 1
#endif

#ifndef    JUCE_DONT_AUTOLINK_TO_WIN32_LIBRARIES
 //#define JUCE_DONT_AUTOLINK_TO_WIN32_LIBRARIES 0
#endif

#ifndef    JUCE_INCLUDE_ZLIB_CODE
 //#define JUCE_INCLUDE_ZLIB_CODE 1
#endif

#ifndef    JUCE_USE_CURL
 //#define JUCE_USE_CURL 1
#endif

#ifndef    JUCE_LOAD_CURL_SYMBOLS_LAZILY
 #define   JUCE_LOAD_CURL_SYMBOLS_LAZILY 1
#endif

#ifndef    JUCE_CATCH_UNHANDLED_EXCEPTIONS
 //#define JUCE_CATCH_UNHANDLED_EXCEPTIONS 0
#endif

#ifndef    JUCE_ALLOW_STATIC_NULL_VARIABLES
 //#define JUCE_ALLOW_STATIC_NULL_VARIABLES 0
#endif

#ifndef    JUCE_STRICT_REFCOUNTEDPOINTER
 //#define JUCE_STRICT_REFCOUNTEDPOINTER 0
#endif

#ifndef    JUCE_ENABLE_ALLOCATION_HOOKS
 //#define JUCE_ENABLE_ALLOCATION_HOOKS 0
#endif

//==============================================================================
// juce_dsp flags:

#ifndef    JUCE_ASSERTION_FIRFILTER
 //#define JUCE_ASSERTION_FIRFILTER 1
#endif

#ifndef    JUCE_DSP_USE_INTEL_MKL
 //#define JUCE_DSP_USE_INTEL_MKL 0
#endif

#ifndef    JUCE_DSP_USE_SHARED_FFTW
 //#define JUCE_DSP_USE_SHARED_FFTW 0
#endif

#ifndef    JUCE_DSP_USE_STATIC_FFTW
 //#define JUCE_DSP_USE_STATIC_FFTW 0
#endif

#ifndef    JUCE_DSP_ENABLE_SNAP_TO_ZERO
 //#define JUCE_DSP_ENABLE_SNAP_TO_ZERO 1
#endif

//==============================================================================
// juce_events flags:

#ifndef    JUCE_EXECUTE_APP_SUSPEND_ON_BACKGROUND_TASK
 //#define JUCE_EXECUTE_APP_SUSPEND_ON_BACKGROUND_TASK 0
#endif

//==============================================================================
// juce_graphics flags:

#ifndef    JUCE_USE_COREIMAGE_LOADER
 //#define JUCE_USE_COREIMAGE_LOADER 1
#endif

#ifndef    JUCE_USE_DIRECTWRITE
 //#define JUCE_USE_DIRECTWRITE 1
#endif

#ifndef    JUCE_DISABLE_COREGRAPHICS_FONT_SMOOTHING
 //#define JUCE_DISABLE_COREGRAPHICS_FONT_SMOOTHING 0
#endif

//==============================================================================
// juce_gui_basics flags:

#ifndef    JUCE_ENABLE_REPAINT_DEBUGGING
 //#define JUCE_ENABLE_REPAINT_DEBUGGING 0
#endif

#ifndef    JUCE_USE_XRANDR
 //#define JUCE_USE_XRANDR 1
#endif

#ifndef    JUCE_USE_XINERAMA
 //#define JUCE_USE_XINERAMA 1
#endif

#ifndef    JUCE_USE_XSHM
 //#define JUCE_USE_XSHM 1
#endif

#ifndef    JUCE_USE_XRENDER
 //#define JUCE_USE_XRENDER 0
#endif

#ifndef    JUCE_USE_XCURSOR
 //#define JUCE_USE_XCURSOR 1
#endif

#ifndef    JUCE_WIN_PER_MONITOR_DPI_AWARE
 //#define JUCE_WIN_PER_MONITOR_DPI_AWARE 1
#endif

//==============================================================================
#ifndef    JUCE_STANDALONE_APPLICATION
 #if defined(JucePlugin_Name) && defined(JucePlugin_Build_Standalone)
  #define  JUCE_STANDALONE_APPLICATION JucePlugin_Build_Standalone
 #else
  #define  JUCE_STANDALONE_APPLICATION 0
 #endif
#endif
