#include "about.h"

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
//                                         DocumentWindow::closeButton | DocumentWindow::minimiseButton,
//                                         true);

	window->setTitleBarHeight(24);
//	window->setUsingNativeTitleBar(true);

    // set window visible
    window->toFront (true);
    window->setVisible (true);

//	Image &icon= *ImageCache::getFromMemory(about::icon_png, about::icon_pngSize);
//	//window->setIcon(&icon);
//	window->getPeer()->setIcon(icon);
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
