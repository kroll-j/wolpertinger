/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  17 Mar 2010 5:47:24pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_TABBEDEDITOR_TABBEDEDITOR_F921B809__
#define __JUCER_HEADER_TABBEDEDITOR_TABBEDEDITOR_F921B809__

//[Headers]     -- You can add your own extra header files here --
#include "juce.h"
#include "PresetComboBox.h"
#include "KeyboardButton.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class tabbed_editor  : public AudioProcessorEditor,
                       public ComboBoxListener
{
public:
    //==============================================================================
    tabbed_editor (AudioProcessor *const ownerFilter);
    ~tabbed_editor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);


    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	struct myLookAndFeel
	{
		myLookAndFeel()
		{
			LookAndFeel &look= LookAndFeel::getDefaultLookAndFeel();
			look.setColour(ComboBox::backgroundColourId, Colour(0xFF101830));
			look.setColour(ComboBox::textColourId, Colour(0xFFF0F0F0));
			look.setColour(ComboBox::outlineColourId, Colour(0xFF404040));
			look.setColour(ComboBox::buttonColourId, Colour(0xFF607080));
			look.setColour(ComboBox::arrowColourId, Colour(0xFF000000));
			look.setColour(TextButton::buttonColourId, Colour(0xFF405068));
			look.setColour(TextButton::textColourOnId, Colour(0xFFFFFFFF));
			look.setColour(TextButton::textColourOffId, Colour(0xFFFFFFFF));
			look.setColour(PopupMenu::backgroundColourId, Colour(0xFFA0B0C0));
			look.setColour(PopupMenu::textColourId, Colour(0xFF000000));
			look.setColour(PopupMenu::highlightedBackgroundColourId, Colour(0xFF204060));

		}
	} __myLookAndFeel;

    MidiKeyboardState midi_keyboard_state;
    KeyboardButton *kbd_button;
    //[/UserVariables]

    //==============================================================================
    MidiKeyboardComponent* midi_keyboard;
    TabbedComponent* tabbedEditor;
    PresetComboBox* comboBox;
    Path internalPath1;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    tabbed_editor (const tabbed_editor&);
    const tabbed_editor& operator= (const tabbed_editor&);
};


#endif   // __JUCER_HEADER_TABBEDEDITOR_TABBEDEDITOR_F921B809__
