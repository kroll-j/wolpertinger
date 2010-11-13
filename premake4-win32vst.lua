-- set this to false if you want to use your own copy of JUCE
juce_amalgamated= true

-- if you set juce_amalgamated to false, adjust this to match your juce basedir containing the 'src' subdirectory
jucedir= "../juce"

-- adjust this to match your vst sdk 2.4 basedir containing the 'public.sdk' subdirectory
vstdir= "../vstsdk2.4"

appname= "Wolpertinger"
version= "004"
version_string= "0.4"

solution(appname)
	if juce_amalgamated then 
		includedirs { "juce" } 
	else
		includedirs { jucedir }
	end

	includedirs {
		vstdir,
		"src",
	}


	buildoptions {
		"`freetype-config --cflags`",
		"-DJUCE_MINGW"
	}
	
	libdirs {
		jucedir .. "/bin",
		-- "/usr/X11R6/lib",
		-- "/usr/lib" 
	}

	configurations { "Release", "Debug" }
	objdir "build-w32vst"
	targetdir "build-w32vst"
	targetprefix ""
	targetname(appname .. version)

	defines { "_WIN32=1",
		  -- "LINUX=1", "JUCE_USE_XSHM=1", "JUCE_ALSA=1", "JUCE_JACK=1", 
		  "JUCE_USE_VSTSDK_2_4=1",
		  "DATE=\"`date +%F`\"",
		  "VERSION=" .. version,
		  "VERSIONSTRING=\"" .. version_string .. "\""
		}

	files { "src/**.cpp", "src/**.h" }

	if juce_amalgamated then files { "juce/*.cpp", "juce/*.h" } end

	links { "freetype", "pthread", "m" }

configuration "Debug"
	defines { "CONFIGURATION=\"Debug\"", "JUCE_DEBUG" }

configuration "Release"
	defines { "CONFIGURATION=\"Release\"" }



project(appname .. "W32VST")
	kind "SharedLib"
	language "C++"
	files { "vst/**.cpp", "vst/**.h" }
	defines { "CONFIG_VST=1", "BINTYPE=\"Win32 VST\"" }
	buildoptions { "-msse" }

configuration "Debug"
	defines { "DEBUG=1", "_DEBUG=1" }
	if not juce_amalgamated then links { "juce_debug" } end
	flags { "Symbols" }
	buildoptions { "-ggdb" }
	targetsuffix "-debug"

configuration "Release"
	defines { "NDEBUG=1" }
	if not juce_amalgamated then links { "juce" } end
	flags { "Optimize" }
	buildoptions { "-O2 -ffast-math" }



