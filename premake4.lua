solution "Wolpertinger"
	includedirs {
		"../juced/juce",	-- adjust this to match your juce basedir containing the 'src' subdirectory
		"../vstsdk2.4", 	-- adjust this to match your vst sdk 2.4 basedir containing the 'public.sdk' subdirectory
		"src"
	}

	libdirs {
		"../juced/bin", 	-- adjust this to match your juce bindir
		"/usr/X11R6/lib",
		"/usr/lib" }

	configurations { "Debug", "Release" }
	objdir "build"
	targetname "Wolpertinger002" 
	targetprefix ""

	defines { "LINUX=1", "JUCE_USE_XSHM=1", "JUCE_ALSA=1", "JUCE_USE_VSTSDK_2_4=1" }

	files { "src/**.cpp", "src/**.h" }

	links { "freetype", "pthread", "rt", "X11", "Xext",
		"asound", "m", "png" }


project "WolpertingerVST"
	kind "SharedLib"
	language "C++"
	files { "vst/**.cpp", "vst/**.h" }

configuration "Debug"
	defines { "DEBUG=1", "_DEBUG=1" }
	links { "juce_debug" }
	flags { "Symbols" }
	buildoptions { "-ggdb" }
	targetdir "build/Debug"
	targetsuffix "-debug"

configuration "Release"
	defines { "NDEBUG=1" }
	links { "juce" }
	flags { "Optimize" }
	buildoptions { "-O2" }
	targetdir "build/Release"




project "WolpertingerStandalone"
	kind "WindowedApp"
	language "C++"
	files { "standalone/**.cpp", "standalone/**.h" }

configuration "Debug"
	defines { "DEBUG=1", "_DEBUG=1" }
	links { "juce_debug" }
	flags { "Symbols" }
	buildoptions { "-ggdb" }
	targetdir "build/Debug"
	targetsuffix "-debug"

configuration "Release"
	defines { "NDEBUG=1" }
	links { "juce" }
	flags { "Optimize" }
	buildoptions { "-O2" }
	targetdir "build/Release"

