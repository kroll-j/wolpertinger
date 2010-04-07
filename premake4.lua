appname= "Wolpertinger"
version= "003"
version_string= "0.3"

solution(appname)
	includedirs {
--		"../juced/juce",	-- adjust this to match your juce basedir containing the 'src' subdirectory
		"../juce-git",
		"../vstsdk2.4", 	-- adjust this to match your vst sdk 2.4 basedir containing the 'public.sdk' subdirectory
		"src"
	}

	libdirs {
--		"../juced/bin", 	-- adjust this to match your juce bindir
		"../juce-git/bin",
		"/usr/X11R6/lib",
		"/usr/lib" }

	configurations { "Debug", "Release" }
	objdir "build"
	targetdir "build"
	targetprefix ""
	targetname(appname .. version)

	defines { "LINUX=1", "JUCE_USE_XSHM=1", "JUCE_ALSA=1", "JUCE_USE_VSTSDK_2_4=1",
			  "DATE=\"`date +%F`\"",
			  "VERSION=" .. version,
			  "VERSIONSTRING=\"" .. version_string .. "\""
			}


	files { "src/**.cpp", "src/**.h" }

	links { "freetype", "pthread", "rt", "X11", "Xext",
		"asound", "m", "GL" }

configuration "Debug"
	defines { "CONFIGURATION=\"Debug\"" }

configuration "Release"
	defines { "CONFIGURATION=\"Release\"" }



project(appname .. "Standalone")
	kind "WindowedApp"
	language "C++"
	files { "standalone/**.cpp", "standalone/**.h" }
	defines { "CONFIG_STANDALONE=1", "BINTYPE=\"Linux Standalone\"" }

configuration "Debug"
	defines { "DEBUG=1", "_DEBUG=1" }
	links { "juce_debug" }
	flags { "Symbols" }
	buildoptions { "-ggdb" }
	targetsuffix "-debug"

configuration "Release"
	defines { "NDEBUG=1" }
	links { "juce" }
	flags { "Optimize" }
	buildoptions { "-O2" }




project(appname .. "VST")
	kind "SharedLib"
	language "C++"
	files { "vst/**.cpp", "vst/**.h" }
	defines { "CONFIG_VST=1", "BINTYPE=\"Linux Native VST\"" }

configuration "Debug"
	defines { "DEBUG=1", "_DEBUG=1" }
	links { "juce_debug" }
	flags { "Symbols" }
	buildoptions { "-ggdb" }
	targetsuffix "-debug"

configuration "Release"
	defines { "NDEBUG=1" }
	links { "juce" }
	flags { "Optimize" }
	buildoptions { "-O2" }



