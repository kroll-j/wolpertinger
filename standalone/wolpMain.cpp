#if 0

#include "juce.h"
#include "editor.h"
#include "synth.h"
#include "juce_StandaloneFilterWindow.h"
#include "juce_StandaloneFilterApplication.h"

class WolpertingerMainWindow: public DocumentWindow
{
	private:
		editor *e;
		wolp *synth;

	public:
		WolpertingerMainWindow():
			DocumentWindow("test", Colour(255, 255, 255), DocumentWindow::allButtons, true)
		{
			synth= new wolp();
			e= new editor(synth);
			setContentComponent(e, false, true);
			setVisible(true);
		}
		~WolpertingerMainWindow()
		{
			delete e;
		}

		void closeButtonPressed() { JUCEApplication::quit(); }
};

//==============================================================================
class WolpertingerApp : public JUCEApplication
{
//	WolpertingerMainWindow *window;
    StandaloneFilterWindow *window;

public:
    //==============================================================================
    WolpertingerApp()
    {
        printf("WolpertingerApp()\n");
        fflush(stdout);
    }

    ~WolpertingerApp()
    {
    }

    //==============================================================================
    void initialise (const String& commandLine)
    {
//    	window= new WolpertingerMainWindow();
        window= new StandaloneFilterWindow("Wolpertinger", Colours::aqua.overlaidWith(Colours::grey.withAlpha(0.5f)));
        printf("window= %X, %d\n", window, window->isVisible());
        window->setVisible(true);
    }

    void shutdown()
    {
    	delete window;
    }

    //==============================================================================
    void systemRequestedQuit()
    {
		quit();
    }

    //==============================================================================
    const String getApplicationName()
    {
        return T("Wolpertinger");
    }

    const String getApplicationVersion()
    {
        return String(0.1);
    }

    bool moreThanOneInstanceAllowed()
    {
#ifndef JUCE_LINUX
        return false;
#else
        return true; //xxx should be false but doesn't work on linux..
#endif
    }

    void anotherInstanceStarted (const String& commandLine)
    {
    }
};


START_JUCE_APPLICATION(WolpertingerApp)

#endif



#include "extras/audio plugins/wrapper/Standalone/juce_AudioFilterStreamer.cpp"
#include "extras/audio plugins/wrapper/Standalone/juce_StandaloneFilterWindow.cpp"
#include "extras/audio plugins/wrapper/Standalone/juce_StandaloneFilterApplication.cpp"

START_JUCE_APPLICATION(StandaloneFilterApplication)
