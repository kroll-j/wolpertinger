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

//[Headers] You can add your own extra header files here...
#include "synth.h"
//[/Headers]

#include "tabbed-editor.h"
#include "editor.h"
#include "about.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
tabbed_editor::tabbed_editor (AudioProcessor *const ownerFilter)
    : AudioProcessorEditor(ownerFilter), kbd_button(0),
      midi_keyboard (0),
      tabbedEditor (0),
      comboBox (0)
{
    addAndMakeVisible (midi_keyboard = new MidiKeyboardComponent (midi_keyboard_state,
                                                                  MidiKeyboardComponent::horizontalKeyboard));
    midi_keyboard->setName (T("new component"));

    addAndMakeVisible (tabbedEditor = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    tabbedEditor->setTabBarDepth (28);
    tabbedEditor->addTab (T("Parameters"), Colour (0xff272727), new editor (ownerFilter), true);
    tabbedEditor->addTab (T("About"), Colour (0xff272727), new about(), true);
    tabbedEditor->setCurrentTabIndex (0);

    addAndMakeVisible (comboBox = new PresetComboBox (T("new combo box")));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centred);
    comboBox->setTextWhenNothingSelected (String::empty);
    comboBox->setTextWhenNoChoicesAvailable (T("(no choices)"));
    comboBox->addItem (T("Bass Drone 1"), 1);
    comboBox->addItem (T("Bass Drone 2"), 2);
    comboBox->addItem (T("Lead Swirl"), 3);
    comboBox->addItem (T("Preset X"), 4);
    comboBox->addItem (T("----"), 5);
    comboBox->addItem (T("Save"), 6);
    comboBox->addItem (T("Save As..."), 7);
    comboBox->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 520);

    //[Constructor] You can add your own custom stuff here..
    midi_keyboard_state.addListener((wolp*)ownerFilter);
	midi_keyboard->setKeyWidth(12);
	midi_keyboard->setColour(MidiKeyboardComponent::whiteNoteColourId, Colour(192, 192, 192));
	midi_keyboard->setColour(MidiKeyboardComponent::mouseOverKeyOverlayColourId, Colour(240, 240, 240));
	midi_keyboard->setColour(MidiKeyboardComponent::keyDownOverlayColourId, Colour(0, 0, 0));
	midi_keyboard->setColour(MidiKeyboardComponent::upDownButtonBackgroundColourId, Colour(192, 192, 192));
//	midi_keyboard->setVelocity(1.0, true);

//	comboBox->initItems();
	comboBox->setVisible(false);

#ifdef CONFIG_STANDALONE
    addAndMakeVisible (kbd_button = new KeyboardButton (String::empty));
    kbd_button->setColour (ToggleButton::textColourId, Colours::white);
    kbd_button->setBounds (2, 444, getWidth()-4, 16);
#endif
    //[/Constructor]
}

tabbed_editor::~tabbed_editor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (midi_keyboard);
    deleteAndZero (tabbedEditor);
    deleteAndZero (comboBox);

    //[Destructor]. You can add your own custom destruction code here..
#ifdef CONFIG_STANDALONE
    deleteAndZero (kbd_button);
#endif
    //[/Destructor]
}

//==============================================================================
void tabbed_editor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff404040));

    g.setGradientFill (ColourGradient (Colour (0xff505050),
                                       122.0f, (float) (-4),
                                       Colour (0xff303030),
                                       126.0f, 34.0f,
                                       false));
    g.fillPath (internalPath1);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void tabbed_editor::resized()
{
    midi_keyboard->setBounds (0, 464, 400, 56);
    tabbedEditor->setBounds (0, 0, 400, 464);
    comboBox->setBounds (290, 6, 104, 16);
    internalPath1.clear();
    internalPath1.startNewSubPath (0.0f, 32.0f);
    internalPath1.lineTo (0.0f, 0.0f);
    internalPath1.lineTo (400.0f, 0.0f);
    internalPath1.lineTo (400.0f, 32.0f);
    internalPath1.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void tabbed_editor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="tabbed_editor" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="AudioProcessor *const ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter), kbd_button(0)"
                 snapPixels="2" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="400" initialHeight="520">
  <BACKGROUND backgroundColour="ff404040">
    <PATH pos="0 0 100 100" fill="linear: 122 -4, 126 34, 0=ff505050, 1=ff303030"
          hasStroke="0" nonZeroWinding="1">s 0 32 l 0 0 l 400 0 l 400 32 x</PATH>
  </BACKGROUND>
  <GENERICCOMPONENT name="new component" id="bbb690ecc3998aec" memberName="midi_keyboard"
                    virtualName="" explicitFocusOrder="0" pos="0 464 400 56" class="MidiKeyboardComponent"
                    params="midi_keyboard_state,&#10;MidiKeyboardComponent::horizontalKeyboard"/>
  <TABBEDCOMPONENT name="tabbedEditor" id="eedf7b50f4218e4" memberName="tabbedEditor"
                   virtualName="" explicitFocusOrder="0" pos="0 0 400 464" orientation="top"
                   tabBarDepth="28" initialTab="0">
    <TAB name="Parameters" colour="ff272727" useJucerComp="1" contentClassName="asdf"
         constructorParams="ownerFilter" jucerComponentFile="editor.cpp"/>
    <TAB name="About" colour="ff272727" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="about.cpp"/>
  </TABBEDCOMPONENT>
  <COMBOBOX name="new combo box" id="dcc06fc0e979f2e7" memberName="comboBox"
            virtualName="PresetComboBox" explicitFocusOrder="0" pos="290 6 104 16"
            editable="0" layout="36" items="Bass Drone 1&#10;Bass Drone 2&#10;Lead Swirl&#10;Preset X&#10;----&#10;Save&#10;Save As..."
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
