/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  8 Nov 2010 6:18:32pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_ABOUT_ABOUT_BA9F930A__
#define __JUCER_HEADER_ABOUT_ABOUT_BA9F930A__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class about  : public Component
{
public:
    //==============================================================================
    about ();
    ~about();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void changeListenerCallback(void *objectThatHasChanged);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* logo_png;
    static const int logo_pngSize;
    static const char* icon_png;
    static const int icon_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    HyperlinkButton* hyperlinkButton;
    Label* label;
    Label* label2;
    Image* cachedImage_logo_png;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    about (const about&);
    const about& operator= (const about&);
};


#endif   // __JUCER_HEADER_ABOUT_ABOUT_BA9F930A__
