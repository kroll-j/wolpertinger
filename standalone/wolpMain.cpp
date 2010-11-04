#include <stdint.h>
#include <cfloat>
#include "about.h"
#include "synth.h"

#include "../vst/juce_PluginHeaders.h"

#include "extras/audio plugins/wrapper/Standalone/juce_AudioFilterStreamer.cpp"
#include "extras/audio plugins/wrapper/Standalone/juce_StandaloneFilterWindow.cpp"

//==============================================================================
/**
    A class that can be used to run a simple standalone application containing your filter.

    Just create one of these objects in your JUCEApplication::initialise() method, and
    let it do its work. It will create your filter object using the same createFilter() function
    that the other plugin wrappers use.
*/
class StandaloneFilterApplication : public JUCEApplication
{
public:

    //==============================================================================
    StandaloneFilterApplication();
    ~StandaloneFilterApplication();

    //==============================================================================
    void initialise (const String& commandLine);
    void shutdown();

    //==============================================================================
    void systemRequestedQuit();
    void unhandledException (const std::exception* e,
                             const String& sourceFilename,
                             const int lineNumber);

    //==============================================================================
    const String getApplicationName();
    const String getApplicationVersion();

    //==============================================================================
    bool moreThanOneInstanceAllowed();

private:

    StandaloneFilterWindow* window;

    StandaloneFilterApplication (const StandaloneFilterApplication&);
    const StandaloneFilterApplication& operator= (const StandaloneFilterApplication&);

    void perfTest();
};

//==============================================================================
StandaloneFilterApplication::StandaloneFilterApplication()
  : window (0)
{
}

StandaloneFilterApplication::~StandaloneFilterApplication()
{
}



//==============================================================================
void StandaloneFilterApplication::perfTest()
{
	wolp *synth= new wolp();
	enum { sampleRate=48000, testSamples=500, nTestsPerLoop=10, nTests=1000 };
	AudioSampleBuffer buffer(2, testSamples);
	double clocksPerSampleMin= DBL_MAX;

	synth->prepareToPlay(sampleRate, 512);

	synth->noteOn(0, 64, 1.0);
	MidiBuffer midiBuf;
	double clocksPerSampleAvg= 0;
	for(int i= 0; i<nTests; i++)
	{
		uint64_t startClocks= rdtsc();
		for(int k= 0; k<nTestsPerLoop; k++)
			synth->processBlock(buffer, midiBuf);
		uint64_t endClocks= rdtsc();
		double ticksPerSample= double(endClocks-startClocks)/(testSamples*nTestsPerLoop);
		if(ticksPerSample<clocksPerSampleMin) clocksPerSampleMin= ticksPerSample;
		clocksPerSampleAvg+= ticksPerSample;
	}
	clocksPerSampleAvg/= nTests;
	printf("clocks/sample min: %.0f avg: %.0f\n", clocksPerSampleMin, clocksPerSampleAvg);
}



//==============================================================================
void StandaloneFilterApplication::initialise (const String& commandLine)
{
    DBG ("StandaloneFilterApplication::initialise");

    // open up config
    ApplicationProperties* appProperties = ApplicationProperties::getInstance();
    appProperties->setStorageParameters (T(JucePlugin_Name),
                                         T("conf"),
                                         T(".tumbetoene"),
                                         2000,
                                         PropertiesFile::ignoreCaseOfKeyNames
                                         | PropertiesFile::storeAsXML);

    // setup window name
    String pluginWindowName;
    pluginWindowName << JucePlugin_Name << " v" << JucePlugin_VersionString;
#ifdef JUCE_DEBUG
    pluginWindowName << " (DEBUG)";
#endif

    // create the window
    window = new StandaloneFilterWindow (pluginWindowName,
                                          Colour (32, 32, 32));


	window->setTitleBarHeight(24);
//	window->setUsingNativeTitleBar(true);

    window->toFront (true);
    window->setVisible (true);

//    perfTest();
}

void StandaloneFilterApplication::shutdown()
{
    DBG ("StandaloneFilterApplication::shutdown");

    if (window)
    {
        window->setVisible (false);
        window->setMenuBar (0);
        deleteAndZero (window);
    }

    ApplicationProperties::getInstance()->closeFiles ();
    ApplicationProperties::deleteInstance();
}

//==============================================================================
void StandaloneFilterApplication::systemRequestedQuit()
{
    DBG ("StandaloneFilterApplication::systemRequestedQuit");

    quit ();
}

void StandaloneFilterApplication::unhandledException (const std::exception* e,
                                                      const String& sourceFilename,
                                                      const int lineNumber)
{
#ifndef JUCE_DEBUG
    AlertWindow::showMessageBox (AlertWindow::WarningIcon,
                                 T("Unhandled Exception"),
                                 T("Something bad happened to the application.") );
    quit ();
#endif
}

//==============================================================================
const String StandaloneFilterApplication::getApplicationName()
{
    return T(JucePlugin_Name);
}

const String StandaloneFilterApplication::getApplicationVersion()
{
    return T(JucePlugin_VersionString);
}

//==============================================================================
bool StandaloneFilterApplication::moreThanOneInstanceAllowed()
{
    return true;
}


START_JUCE_APPLICATION(StandaloneFilterApplication)
