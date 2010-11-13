ifndef config
  config=release
endif

ifndef verbose
  SILENT = @
endif

#ifndef CC
  CC = i586-mingw32msvc-gcc
#endif

#ifndef CXX
  CXX = i586-mingw32msvc-g++
#endif

#ifndef AR
  AR = i586-mingw32msvc-ar
#endif

ifeq ($(config),release)
  OBJDIR     = build-w32vst/Release
  TARGETDIR  = build-w32vst
  TARGET     = $(TARGETDIR)/Wolpertinger004.dll
  DEFINES   += -D_WIN32=1 -DJUCE_USE_VSTSDK_2_4=1 -DDATE="`date +%F`" -DVERSION=004 -DVERSIONSTRING="0.4" -DCONFIGURATION="Release" -DCONFIG_VST=1 -DBINTYPE="Win32 VST" -DNDEBUG=1
  INCLUDES  += -Ijuce -I../vstsdk2.4 -Isrc
  CPPFLAGS  += $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2 `freetype-config --cflags` -DJUCE_MINGW -msse -O2 -ffast-math -march=i686
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -shared -Wl,--out-implib="build-w32vst/Wolpertinger004.a" -L../juce/bin
  LIBS      += -lm -lkernel32 -lgdi32 -lwinmm -lole32 -lwininet -lws2_32 -luuid -lversion -lmsvfw32 -lcomdlg32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

ifeq ($(config),debug)
  OBJDIR     = build-w32vst/Debug
  TARGETDIR  = build-w32vst
  TARGET     = $(TARGETDIR)/Wolpertinger004-debug.dll
  DEFINES   += -D_WIN32=1 -DJUCE_USE_VSTSDK_2_4=1 -DDATE="`date +%F`" -DVERSION=004 -DVERSIONSTRING="0.4" -DCONFIGURATION="Debug" -DJUCE_DEBUG -DCONFIG_VST=1 -DBINTYPE="Win32 VST" -DDEBUG=1 -D_DEBUG=1
  INCLUDES  += -Ijuce -I../vstsdk2.4 -Isrc
  CPPFLAGS  += $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g `freetype-config --cflags` -DJUCE_MINGW -msse -ggdb -march=i686
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -shared -Wl,--out-implib="build-w32vst/Wolpertinger004-debug.a" -L../juce/bin
  LIBS      += -lm -lkernel32 -lgdi32 -lwinmm -lole32 -lwininet -lws2_32 -luuid -lversion -lmsvfw32 -lcomdlg32
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
  endef
endif

OBJECTS := \
	$(OBJDIR)/ADSRenv.o \
	$(OBJDIR)/KeyboardButton.o \
	$(OBJDIR)/PresetComboBox.o \
	$(OBJDIR)/RotatingToggleButton.o \
	$(OBJDIR)/synth.o \
	$(OBJDIR)/tabbed-editor.o \
	$(OBJDIR)/about.o \
	$(OBJDIR)/editor.o \
	$(OBJDIR)/juce_amalgamated.o \
	$(OBJDIR)/juce_VST_Wrapper.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking WolpertingerW32VST
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning WolpertingerW32VST
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<
endif

$(OBJDIR)/ADSRenv.o: src/ADSRenv.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<
$(OBJDIR)/KeyboardButton.o: src/KeyboardButton.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<
$(OBJDIR)/PresetComboBox.o: src/PresetComboBox.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<
$(OBJDIR)/RotatingToggleButton.o: src/RotatingToggleButton.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<
$(OBJDIR)/synth.o: src/synth.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<
$(OBJDIR)/tabbed-editor.o: src/tabbed-editor.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<
$(OBJDIR)/about.o: src/about.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<
$(OBJDIR)/editor.o: src/editor.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<
$(OBJDIR)/juce_amalgamated.o: juce/juce_amalgamated.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<
$(OBJDIR)/juce_VST_Wrapper.o: vst/juce_VST_Wrapper.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o $@ -c $<

-include $(OBJECTS:%.o=%.d)
