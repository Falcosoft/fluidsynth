/* Fixed MSVC 2019 configuration for the SF2-only VST runtime.
   No CMake/configure step is required. This header is shared by Win32/x64.
   POSIX/MinGW-only headers and variable-length arrays are intentionally absent. */
#ifndef CONFIG_H
#define CONFIG_H

#define PACKAGE "fluidsynth"
#define DEFAULT_SOUNDFONT "C:\\ProgramData\\soundfonts\\default.sf2"

#define HAVE_WINDOWS_H 1
#define HAVE_ERRNO_H 1
#define HAVE_FCNTL_H 1
#define HAVE_IO_H 1
#define HAVE_LIMITS_H 1
#define HAVE_MATH_H 1
#define HAVE_SIGNAL_H 1
#define HAVE_STDARG_H 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_TYPES_H 1
#define STDC_HEADERS 1

#define HAVE_SINF 1
#define HAVE_COSF 1
#define HAVE_FABSF 1
#define HAVE_POWF 1
#define HAVE_SQRTF 1
#define HAVE_LOGF 1

#define OSAL_cpp11 1
#define HAVE_CXX_FILESYSTEM 1
#define ENABLE_MIXER_THREADS 1
#define WITH_FLOAT 1

/* MSVC's C mode uses __inline. C++ keeps the language keyword unchanged. */
#if defined(_MSC_VER) && !defined(__cplusplus)
#ifndef inline
#define inline __inline
#endif
#endif

/* Disabled optional features are left undefined, not defined to zero:
   LIBSNDFILE_SUPPORT, LIBSNDFILE_HASVORBIS, ENABLE_NATIVE_DLS,
   SIGNALSMITH_SUPPORT, HAVE_OPENMP, AUFILE_SUPPORT, NETWORK_SUPPORT,
   IPV6_SUPPORT, DSOUND_SUPPORT, WASAPI_SUPPORT, WAVEOUT_SUPPORT,
   WINMIDI_SUPPORT, SDL3_SUPPORT, LADSPA, PORTAUDIO_SUPPORT,
   READLINE_SUPPORT, ALSA_SUPPORT, PULSE_SUPPORT, PIPEWIRE_SUPPORT,
   JACK_SUPPORT, DBUS_SUPPORT, MINGW32, SUPPORTS_VLA, WORDS_BIGENDIAN. */

#endif /* CONFIG_H */
