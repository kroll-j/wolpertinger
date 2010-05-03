/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  30 Apr 2010 5:44:31pm

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
#include "about.h"
//[/Headers]

#include "editor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
editor::editor (AudioProcessor *const ownerFilter)
    : AudioProcessorEditor(ownerFilter),
      groupComponent2 (0),
      groupComponent (0),
      label (0),
      label2 (0),
      slgain (0),
      slclip (0),
      slsaw (0),
      label3 (0),
      slrect (0),
      label4 (0),
      sltri (0),
      label5 (0),
      sltune (0),
      label6 (0),
      groupComponent3 (0),
      label7 (0),
      slcutoff (0),
      label8 (0),
      slreso (0),
      label9 (0),
      slbandwidth (0),
      label10 (0),
      slpasses (0),
      label11 (0),
      slvelocity (0),
      label12 (0),
      slinertia (0),
      label13 (0),
      slcurcutoff (0),
      label14 (0),
      label15 (0),
      label19 (0),
      label20 (0),
      label16 (0),
      label17 (0),
      label18 (0),
      slattack5 (0),
      slattack6 (0),
      label21 (0),
      label22 (0),
      slattack7 (0),
      knobAttack (0),
      knobDecay (0),
      knobSustain (0),
      knobRelease (0)
{
    addAndMakeVisible (groupComponent2 = new GroupComponent (T("new group"),
                                                             T("Oscillators")));
    groupComponent2->setExplicitFocusOrder (1);
    groupComponent2->setTextLabelPosition (Justification::centredLeft);
    groupComponent2->setColour (GroupComponent::outlineColourId, Colour (0x66ffffff));
    groupComponent2->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (groupComponent = new GroupComponent (T("new group"),
                                                            T("Output")));
    groupComponent->setExplicitFocusOrder (1);
    groupComponent->setTextLabelPosition (Justification::centredLeft);
    groupComponent->setColour (GroupComponent::outlineColourId, Colour (0x66ffffff));
    groupComponent->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (label = new Label (T("new label"),
                                          T("Gain")));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredRight);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label2 = new Label (T("new label"),
                                           T("Clip")));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredRight);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colours::white);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slgain = new Slider (T("new slider")));
    slgain->setRange (0, 4, 0.0001);
    slgain->setSliderStyle (Slider::LinearHorizontal);
    slgain->setTextBoxStyle (Slider::TextBoxRight, false, 60, 20);
    slgain->setColour (Slider::backgroundColourId, Colour (0x868686));
    slgain->setColour (Slider::textBoxTextColourId, Colours::white);
    slgain->setColour (Slider::textBoxBackgroundColourId, Colour (0x565656));
    slgain->setColour (Slider::textBoxHighlightColourId, Colour (0x409a9aff));
    slgain->setColour (Slider::textBoxOutlineColourId, Colour (0x0));
    slgain->addListener (this);
    slgain->setSkewFactor (0.3);

    addAndMakeVisible (slclip = new Slider (T("new slider")));
    slclip->setRange (0, 5, 0.0001);
    slclip->setSliderStyle (Slider::LinearHorizontal);
    slclip->setTextBoxStyle (Slider::TextBoxRight, false, 60, 20);
    slclip->setColour (Slider::backgroundColourId, Colour (0x868686));
    slclip->setColour (Slider::textBoxTextColourId, Colours::white);
    slclip->setColour (Slider::textBoxBackgroundColourId, Colour (0x565656));
    slclip->setColour (Slider::textBoxHighlightColourId, Colour (0x409a9aff));
    slclip->setColour (Slider::textBoxOutlineColourId, Colour (0x0));
    slclip->addListener (this);
    slclip->setSkewFactor (0.5);

    addAndMakeVisible (slsaw = new Slider (T("new slider")));
    slsaw->setRange (0, 1, 0);
    slsaw->setSliderStyle (Slider::Rotary);
    slsaw->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slsaw->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    slsaw->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    slsaw->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    slsaw->addListener (this);

    addAndMakeVisible (label3 = new Label (T("new label"),
                                           T("Saw")));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (Label::textColourId, Colours::white);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slrect = new Slider (T("new slider")));
    slrect->setRange (0, 1, 0);
    slrect->setSliderStyle (Slider::Rotary);
    slrect->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slrect->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    slrect->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    slrect->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    slrect->addListener (this);

    addAndMakeVisible (label4 = new Label (T("new label"),
                                           T("Rect")));
    label4->setFont (Font (15.0000f, Font::plain));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (Label::textColourId, Colours::white);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (sltri = new Slider (T("new slider")));
    sltri->setRange (0, 1, 0);
    sltri->setSliderStyle (Slider::Rotary);
    sltri->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    sltri->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    sltri->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    sltri->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    sltri->addListener (this);

    addAndMakeVisible (label5 = new Label (T("new label"),
                                           T("Tri")));
    label5->setFont (Font (15.0000f, Font::plain));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (Label::textColourId, Colours::white);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (sltune = new Slider (T("new slider")));
    sltune->setRange (0, 1, 0);
    sltune->setSliderStyle (Slider::Rotary);
    sltune->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    sltune->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    sltune->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    sltune->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    sltune->addListener (this);

    addAndMakeVisible (label6 = new Label (T("new label"),
                                           T("Tune")));
    label6->setFont (Font (15.0000f, Font::plain));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (Label::textColourId, Colours::white);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (groupComponent3 = new GroupComponent (T("new group"),
                                                             T("Filter")));
    groupComponent3->setExplicitFocusOrder (1);
    groupComponent3->setTextLabelPosition (Justification::centredLeft);
    groupComponent3->setColour (GroupComponent::outlineColourId, Colour (0x66ffffff));
    groupComponent3->setColour (GroupComponent::textColourId, Colours::white);

    addAndMakeVisible (label7 = new Label (T("new label"),
                                           T("Filter X")));
    label7->setFont (Font (15.0000f, Font::plain));
    label7->setJustificationType (Justification::centredRight);
    label7->setEditable (false, false, false);
    label7->setColour (Label::textColourId, Colours::white);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slcutoff = new Slider (T("new slider")));
    slcutoff->setRange (0, 4, 0.0001);
    slcutoff->setSliderStyle (Slider::LinearHorizontal);
    slcutoff->setTextBoxStyle (Slider::TextBoxRight, false, 60, 20);
    slcutoff->setColour (Slider::backgroundColourId, Colour (0x868686));
    slcutoff->setColour (Slider::textBoxTextColourId, Colours::white);
    slcutoff->setColour (Slider::textBoxBackgroundColourId, Colour (0x565656));
    slcutoff->setColour (Slider::textBoxHighlightColourId, Colour (0x409a9aff));
    slcutoff->setColour (Slider::textBoxOutlineColourId, Colour (0x0));
    slcutoff->addListener (this);
    slcutoff->setSkewFactor (0.5);

    addAndMakeVisible (label8 = new Label (T("new label"),
                                           T("Resonance")));
    label8->setFont (Font (15.0000f, Font::plain));
    label8->setJustificationType (Justification::centredRight);
    label8->setEditable (false, false, false);
    label8->setColour (Label::textColourId, Colours::white);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slreso = new Slider (T("new slider")));
    slreso->setRange (0, 4, 0.0001);
    slreso->setSliderStyle (Slider::LinearHorizontal);
    slreso->setTextBoxStyle (Slider::TextBoxRight, false, 60, 20);
    slreso->setColour (Slider::backgroundColourId, Colour (0x868686));
    slreso->setColour (Slider::textBoxTextColourId, Colours::white);
    slreso->setColour (Slider::textBoxBackgroundColourId, Colour (0x565656));
    slreso->setColour (Slider::textBoxHighlightColourId, Colour (0x409a9aff));
    slreso->setColour (Slider::textBoxOutlineColourId, Colour (0x0));
    slreso->addListener (this);
    slreso->setSkewFactor (0.5);

    addAndMakeVisible (label9 = new Label (T("new label"),
                                           T("Bandwidth")));
    label9->setFont (Font (15.0000f, Font::plain));
    label9->setJustificationType (Justification::centredRight);
    label9->setEditable (false, false, false);
    label9->setColour (Label::textColourId, Colours::white);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slbandwidth = new Slider (T("new slider")));
    slbandwidth->setRange (0, 4, 0.0001);
    slbandwidth->setSliderStyle (Slider::LinearHorizontal);
    slbandwidth->setTextBoxStyle (Slider::TextBoxRight, false, 60, 20);
    slbandwidth->setColour (Slider::backgroundColourId, Colour (0x868686));
    slbandwidth->setColour (Slider::textBoxTextColourId, Colours::white);
    slbandwidth->setColour (Slider::textBoxBackgroundColourId, Colour (0x565656));
    slbandwidth->setColour (Slider::textBoxHighlightColourId, Colour (0x409a9aff));
    slbandwidth->setColour (Slider::textBoxOutlineColourId, Colour (0x0));
    slbandwidth->addListener (this);
    slbandwidth->setSkewFactor (0.5);

    addAndMakeVisible (label10 = new Label (T("new label"),
                                            T("Passes")));
    label10->setFont (Font (15.0000f, Font::plain));
    label10->setJustificationType (Justification::centredRight);
    label10->setEditable (false, false, false);
    label10->setColour (Label::textColourId, Colours::white);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slpasses = new Slider (T("new slider")));
    slpasses->setRange (0, 4, 0.0001);
    slpasses->setSliderStyle (Slider::LinearHorizontal);
    slpasses->setTextBoxStyle (Slider::TextBoxRight, false, 60, 20);
    slpasses->setColour (Slider::backgroundColourId, Colour (0x868686));
    slpasses->setColour (Slider::textBoxTextColourId, Colours::white);
    slpasses->setColour (Slider::textBoxBackgroundColourId, Colour (0x565656));
    slpasses->setColour (Slider::textBoxHighlightColourId, Colour (0x409a9aff));
    slpasses->setColour (Slider::textBoxOutlineColourId, Colour (0x0));
    slpasses->addListener (this);

    addAndMakeVisible (label11 = new Label (T("new label"),
                                            T("Velocity")));
    label11->setFont (Font (15.0000f, Font::plain));
    label11->setJustificationType (Justification::centredRight);
    label11->setEditable (false, false, false);
    label11->setColour (Label::textColourId, Colours::white);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slvelocity = new Slider (T("new slider")));
    slvelocity->setRange (0, 4, 0.0001);
    slvelocity->setSliderStyle (Slider::LinearHorizontal);
    slvelocity->setTextBoxStyle (Slider::TextBoxRight, false, 60, 20);
    slvelocity->setColour (Slider::backgroundColourId, Colour (0x868686));
    slvelocity->setColour (Slider::textBoxTextColourId, Colours::white);
    slvelocity->setColour (Slider::textBoxBackgroundColourId, Colour (0x565656));
    slvelocity->setColour (Slider::textBoxHighlightColourId, Colour (0x409a9aff));
    slvelocity->setColour (Slider::textBoxOutlineColourId, Colour (0x0));
    slvelocity->addListener (this);
    slvelocity->setSkewFactor (0.5);

    addAndMakeVisible (label12 = new Label (T("new label"),
                                            T("Inertia")));
    label12->setFont (Font (15.0000f, Font::plain));
    label12->setJustificationType (Justification::centredRight);
    label12->setEditable (false, false, false);
    label12->setColour (Label::textColourId, Colours::white);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slinertia = new Slider (T("new slider")));
    slinertia->setRange (0, 4, 0.0001);
    slinertia->setSliderStyle (Slider::LinearHorizontal);
    slinertia->setTextBoxStyle (Slider::TextBoxRight, false, 60, 20);
    slinertia->setColour (Slider::backgroundColourId, Colour (0x868686));
    slinertia->setColour (Slider::textBoxTextColourId, Colours::white);
    slinertia->setColour (Slider::textBoxBackgroundColourId, Colour (0x565656));
    slinertia->setColour (Slider::textBoxHighlightColourId, Colour (0x409a9aff));
    slinertia->setColour (Slider::textBoxOutlineColourId, Colour (0x0));
    slinertia->addListener (this);
    slinertia->setSkewFactor (0.5);

    addAndMakeVisible (label13 = new Label (T("new label"),
                                            T("Filter Freq")));
    label13->setFont (Font (15.0000f, Font::plain));
    label13->setJustificationType (Justification::centredRight);
    label13->setEditable (false, false, false);
    label13->setColour (Label::textColourId, Colours::white);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slcurcutoff = new Slider (T("new slider")));
    slcurcutoff->setRange (0, 4, 0.0001);
    slcurcutoff->setSliderStyle (Slider::LinearHorizontal);
    slcurcutoff->setTextBoxStyle (Slider::TextBoxRight, false, 60, 20);
    slcurcutoff->setColour (Slider::backgroundColourId, Colour (0x868686));
    slcurcutoff->setColour (Slider::textBoxTextColourId, Colours::white);
    slcurcutoff->setColour (Slider::textBoxBackgroundColourId, Colour (0x565656));
    slcurcutoff->setColour (Slider::textBoxHighlightColourId, Colour (0x409a9aff));
    slcurcutoff->setColour (Slider::textBoxOutlineColourId, Colour (0x0));
    slcurcutoff->addListener (this);
    slcurcutoff->setSkewFactor (0.4);

    addAndMakeVisible (label14 = new Label (T("new label"),
                                            T("Waveform")));
    label14->setFont (Font (15.0000f, Font::plain));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (Label::textColourId, Colours::white);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label15 = new Label (T("new label"),
                                            T("A")));
    label15->setFont (Font (15.0000f, Font::plain));
    label15->setJustificationType (Justification::centred);
    label15->setEditable (false, false, false);
    label15->setColour (Label::textColourId, Colours::white);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label19 = new Label (T("new label"),
                                            T("Inertia")));
    label19->setFont (Font (15.0000f, Font::plain));
    label19->setJustificationType (Justification::centred);
    label19->setEditable (false, false, false);
    label19->setColour (Label::textColourId, Colours::white);
    label19->setColour (TextEditor::textColourId, Colours::black);
    label19->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label20 = new Label (T("new label"),
                                            T("Velocity")));
    label20->setFont (Font (15.0000f, Font::plain));
    label20->setJustificationType (Justification::centred);
    label20->setEditable (false, false, false);
    label20->setColour (Label::textColourId, Colours::white);
    label20->setColour (TextEditor::textColourId, Colours::black);
    label20->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label16 = new Label (T("new label"),
                                            T("D")));
    label16->setFont (Font (15.0000f, Font::plain));
    label16->setJustificationType (Justification::centred);
    label16->setEditable (false, false, false);
    label16->setColour (Label::textColourId, Colours::white);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label17 = new Label (T("new label"),
                                            T("S")));
    label17->setFont (Font (15.0000f, Font::plain));
    label17->setJustificationType (Justification::centred);
    label17->setEditable (false, false, false);
    label17->setColour (Label::textColourId, Colours::white);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label18 = new Label (T("new label"),
                                            T("R")));
    label18->setFont (Font (15.0000f, Font::plain));
    label18->setJustificationType (Justification::centred);
    label18->setEditable (false, false, false);
    label18->setColour (Label::textColourId, Colours::white);
    label18->setColour (TextEditor::textColourId, Colours::black);
    label18->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slattack5 = new Slider (T("new slider")));
    slattack5->setRange (0, 1, 0);
    slattack5->setSliderStyle (Slider::Rotary);
    slattack5->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slattack5->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    slattack5->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    slattack5->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    slattack5->addListener (this);

    addAndMakeVisible (slattack6 = new Slider (T("new slider")));
    slattack6->setRange (0, 1, 0);
    slattack6->setSliderStyle (Slider::Rotary);
    slattack6->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slattack6->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    slattack6->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    slattack6->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    slattack6->addListener (this);

    addAndMakeVisible (label21 = new Label (T("new label"),
                                            T("Scale")));
    label21->setFont (Font (15.0000f, Font::plain));
    label21->setJustificationType (Justification::centred);
    label21->setEditable (false, false, false);
    label21->setColour (Label::textColourId, Colours::white);
    label21->setColour (TextEditor::textColourId, Colours::black);
    label21->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label22 = new Label (T("new label"),
                                            T("Envelope")));
    label22->setFont (Font (15.0000f, Font::plain));
    label22->setJustificationType (Justification::centredLeft);
    label22->setEditable (false, false, false);
    label22->setColour (Label::textColourId, Colours::white);
    label22->setColour (TextEditor::textColourId, Colours::black);
    label22->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (slattack7 = new Slider (T("new slider")));
    slattack7->setRange (0, 1, 0);
    slattack7->setSliderStyle (Slider::Rotary);
    slattack7->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slattack7->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    slattack7->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    slattack7->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    slattack7->addListener (this);

    addAndMakeVisible (knobAttack = new Slider (T("new slider")));
    knobAttack->setRange (0, 1, 0);
    knobAttack->setSliderStyle (Slider::Rotary);
    knobAttack->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    knobAttack->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    knobAttack->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    knobAttack->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    knobAttack->addListener (this);

    addAndMakeVisible (knobDecay = new Slider (T("new slider")));
    knobDecay->setRange (0, 1, 0);
    knobDecay->setSliderStyle (Slider::Rotary);
    knobDecay->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    knobDecay->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    knobDecay->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    knobDecay->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    knobDecay->addListener (this);

    addAndMakeVisible (knobSustain = new Slider (T("new slider")));
    knobSustain->setRange (0, 1, 0);
    knobSustain->setSliderStyle (Slider::Rotary);
    knobSustain->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    knobSustain->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    knobSustain->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    knobSustain->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    knobSustain->addListener (this);

    addAndMakeVisible (knobRelease = new Slider (T("new slider")));
    knobRelease->setRange (0, 1, 0);
    knobRelease->setSliderStyle (Slider::Rotary);
    knobRelease->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    knobRelease->setColour (Slider::thumbColourId, Colour (0xffbbf2ff));
    knobRelease->setColour (Slider::rotarySliderFillColourId, Colour (0x7f00b9ff));
    knobRelease->setColour (Slider::rotarySliderOutlineColourId, Colour (0x80ffffff));
    knobRelease->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 428);

    //[Constructor] You can add your own custom stuff here..

    ((wolp*)ownerFilter)->addChangeListener(this);

    printf("editor() -- Thread: %08X\n", Thread::getCurrentThreadId());



    //[/Constructor]
}

editor::~editor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    ((wolp*)getAudioProcessor())->removeChangeListener(this);
    printf("~editor() -- Thread: %08X\n", Thread::getCurrentThreadId());
    //[/Destructor_pre]

    deleteAndZero (groupComponent2);
    deleteAndZero (groupComponent);
    deleteAndZero (label);
    deleteAndZero (label2);
    deleteAndZero (slgain);
    deleteAndZero (slclip);
    deleteAndZero (slsaw);
    deleteAndZero (label3);
    deleteAndZero (slrect);
    deleteAndZero (label4);
    deleteAndZero (sltri);
    deleteAndZero (label5);
    deleteAndZero (sltune);
    deleteAndZero (label6);
    deleteAndZero (groupComponent3);
    deleteAndZero (label7);
    deleteAndZero (slcutoff);
    deleteAndZero (label8);
    deleteAndZero (slreso);
    deleteAndZero (label9);
    deleteAndZero (slbandwidth);
    deleteAndZero (label10);
    deleteAndZero (slpasses);
    deleteAndZero (label11);
    deleteAndZero (slvelocity);
    deleteAndZero (label12);
    deleteAndZero (slinertia);
    deleteAndZero (label13);
    deleteAndZero (slcurcutoff);
    deleteAndZero (label14);
    deleteAndZero (label15);
    deleteAndZero (label19);
    deleteAndZero (label20);
    deleteAndZero (label16);
    deleteAndZero (label17);
    deleteAndZero (label18);
    deleteAndZero (slattack5);
    deleteAndZero (slattack6);
    deleteAndZero (label21);
    deleteAndZero (label22);
    deleteAndZero (slattack7);
    deleteAndZero (knobAttack);
    deleteAndZero (knobDecay);
    deleteAndZero (knobSustain);
    deleteAndZero (knobRelease);

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void editor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff272727));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void editor::resized()
{
    groupComponent2->setBounds (8, 8, 384, 112);
    groupComponent->setBounds (8, 337, 384, 80);
    label->setBounds (16, 361, 56, 16);
    label2->setBounds (16, 385, 56, 16);
    slgain->setBounds (80, 361, 304, 16);
    slclip->setBounds (80, 385, 304, 16);
    slsaw->setBounds (24, 48, 40, 40);
    label3->setBounds (24, 88, 40, 16);
    slrect->setBounds (72, 48, 40, 40);
    label4->setBounds (72, 88, 40, 16);
    sltri->setBounds (120, 48, 40, 40);
    label5->setBounds (120, 88, 40, 16);
    sltune->setBounds (168, 48, 40, 40);
    label6->setBounds (168, 88, 40, 16);
    groupComponent3->setBounds (8, 129, 384, 200);
    label7->setBounds (16, 153, 64, 16);
    slcutoff->setBounds (80, 153, 304, 16);
    label8->setBounds (16, 177, 64, 16);
    slreso->setBounds (80, 177, 304, 16);
    label9->setBounds (16, 201, 64, 16);
    slbandwidth->setBounds (80, 201, 304, 16);
    label10->setBounds (16, 225, 64, 16);
    slpasses->setBounds (80, 225, 304, 16);
    label11->setBounds (16, 249, 64, 16);
    slvelocity->setBounds (80, 249, 304, 16);
    label12->setBounds (16, 273, 64, 16);
    slinertia->setBounds (80, 273, 304, 16);
    label13->setBounds (16, 297, 64, 16);
    slcurcutoff->setBounds (80, 297, 304, 16);
    label14->setBounds (24, (48) + (40) / 2 + -28 - ((16) / 2), 80, 16);
    label15->setBounds (226, 89, 32, 16);
    label19->setBounds (720, 168, 48, 16);
    label20->setBounds (664, 168, 56, 16);
    label16->setBounds (266, 89, 32, 16);
    label17->setBounds (306, 89, 32, 16);
    label18->setBounds (346, 89, 32, 16);
    slattack5->setBounds (672, 136, 40, 32);
    slattack6->setBounds (728, 136, 32, 32);
    label21->setBounds (616, 168, 48, 16);
    label22->setBounds (224, 32, 136, 16);
    slattack7->setBounds (624, 136, 32, 32);
    knobAttack->setBounds (226, 48, 32, 41);
    knobDecay->setBounds (266, 48, 32, 41);
    knobSustain->setBounds (306, 48, 32, 41);
    knobRelease->setBounds (346, 48, 32, 41);
    //[UserResized] Add your own custom resize handling here..
#if 1
    #define initslider(slidername, param)\
    slidername->setRange(synth->paraminfos[wolp::param].min, synth->paraminfos[wolp::param].max);	\
    slidername->setValue(synth->getParameter(wolp::param)*(synth->paraminfos[wolp::param].max-synth->paraminfos[wolp::param].min));
    wolp *synth= (wolp*)getAudioProcessor();
    initslider(slsaw, gsaw);
    initslider(slrect, grect);
    initslider(sltri, gtri);
    initslider(sltune, tune);
    initslider(slgain, gain);
    initslider(slclip, clip);

    initslider(slcutoff, cutoff);
    initslider(slreso, resonance);
    initslider(slbandwidth, bandwidth);
    initslider(slpasses, nfilters);
    initslider(slvelocity, velocity);
    initslider(slinertia, inertia);
    initslider(slcurcutoff, curcutoff);

    initslider(knobAttack, attack);
    initslider(knobDecay, decay);
    initslider(knobSustain, sustain);
    initslider(knobRelease, release);

    slpasses->setRange(synth->paraminfos[wolp::nfilters].min, synth->paraminfos[wolp::nfilters].max, 1.0);
    slpasses->setValue(synth->getParameter(wolp::nfilters)*(synth->paraminfos[wolp::nfilters].max-synth->paraminfos[wolp::nfilters].min));
    #undef initslider
#endif
    //[/UserResized]
}

void editor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
#if 1
    wolp *synth= (wolp*)getAudioProcessor();
    #define updateval(param)\
    synth->setParameterNotifyingHost( wolp::param, sliderThatWasMoved->getValue() / \
		(synth->paraminfos[wolp::param].max-synth->paraminfos[wolp::param].min) )
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slgain)
    {
        //[UserSliderCode_slgain] -- add your slider handling code here..
		updateval(gain);
        //[/UserSliderCode_slgain]
    }
    else if (sliderThatWasMoved == slclip)
    {
        //[UserSliderCode_slclip] -- add your slider handling code here..
		updateval(clip);
        //[/UserSliderCode_slclip]
    }
    else if (sliderThatWasMoved == slsaw)
    {
        //[UserSliderCode_slsaw] -- add your slider handling code here..
		updateval(gsaw);
        //[/UserSliderCode_slsaw]
    }
    else if (sliderThatWasMoved == slrect)
    {
        //[UserSliderCode_slrect] -- add your slider handling code here..
		updateval(grect);
        //[/UserSliderCode_slrect]
    }
    else if (sliderThatWasMoved == sltri)
    {
        //[UserSliderCode_sltri] -- add your slider handling code here..
		updateval(gtri);
        //[/UserSliderCode_sltri]
    }
    else if (sliderThatWasMoved == sltune)
    {
        //[UserSliderCode_sltune] -- add your slider handling code here..
		updateval(tune);
        //[/UserSliderCode_sltune]
    }
    else if (sliderThatWasMoved == slcutoff)
    {
        //[UserSliderCode_slcutoff] -- add your slider handling code here..
		updateval(cutoff);
        //[/UserSliderCode_slcutoff]
    }
    else if (sliderThatWasMoved == slreso)
    {
        //[UserSliderCode_slreso] -- add your slider handling code here..
		updateval(resonance);
        //[/UserSliderCode_slreso]
    }
    else if (sliderThatWasMoved == slbandwidth)
    {
        //[UserSliderCode_slbandwidth] -- add your slider handling code here..
		updateval(bandwidth);
        //[/UserSliderCode_slbandwidth]
    }
    else if (sliderThatWasMoved == slpasses)
    {
        //[UserSliderCode_slpasses] -- add your slider handling code here..
		updateval(nfilters);
        //[/UserSliderCode_slpasses]
    }
    else if (sliderThatWasMoved == slvelocity)
    {
        //[UserSliderCode_slvelocity] -- add your slider handling code here..
		updateval(velocity);
        //[/UserSliderCode_slvelocity]
    }
    else if (sliderThatWasMoved == slinertia)
    {
        //[UserSliderCode_slinertia] -- add your slider handling code here..
		updateval(inertia);
        //[/UserSliderCode_slinertia]
    }
    else if (sliderThatWasMoved == slcurcutoff)
    {
        //[UserSliderCode_slcurcutoff] -- add your slider handling code here..
		updateval(curcutoff);
        //[/UserSliderCode_slcurcutoff]
    }
    else if (sliderThatWasMoved == slattack5)
    {
        //[UserSliderCode_slattack5] -- add your slider handling code here..
        //[/UserSliderCode_slattack5]
    }
    else if (sliderThatWasMoved == slattack6)
    {
        //[UserSliderCode_slattack6] -- add your slider handling code here..
        //[/UserSliderCode_slattack6]
    }
    else if (sliderThatWasMoved == slattack7)
    {
        //[UserSliderCode_slattack7] -- add your slider handling code here..
        //[/UserSliderCode_slattack7]
    }
    else if (sliderThatWasMoved == knobAttack)
    {
        //[UserSliderCode_knobAttack] -- add your slider handling code here..
        updateval(attack);
        //[/UserSliderCode_knobAttack]
    }
    else if (sliderThatWasMoved == knobDecay)
    {
        //[UserSliderCode_knobDecay] -- add your slider handling code here..
        updateval(decay);
        //[/UserSliderCode_knobDecay]
    }
    else if (sliderThatWasMoved == knobSustain)
    {
        //[UserSliderCode_knobSustain] -- add your slider handling code here..
        updateval(sustain);
        //[/UserSliderCode_knobSustain]
    }
    else if (sliderThatWasMoved == knobRelease)
    {
        //[UserSliderCode_knobRelease] -- add your slider handling code here..
        updateval(release);
        //[/UserSliderCode_knobRelease]
    }

    //[UsersliderValueChanged_Post]
    #undef updateval
#endif
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void editor::changeListenerCallback(void *objectThatHasChanged)
{
    int idx= (int)objectThatHasChanged;
	wolp *synth= (wolp*)getAudioProcessor();
#define updateslider(name, slidername)		\
		case wolp::name:	\
			slidername->setValue( synth->params[wolp::name] * \
								  (synth->paraminfos[idx].max-synth->paraminfos[idx].min), false );	\
			break;

	switch(idx)
	{
		updateslider (gain, slgain);
		updateslider (clip, slclip);
		updateslider (gsaw, slsaw);
		updateslider (grect, slrect);
		updateslider (gtri, sltri);
		updateslider (tune, sltune);
		updateslider (cutoff, slcutoff);
		updateslider (resonance, slreso);
		updateslider (bandwidth, slbandwidth);
		updateslider (velocity, slvelocity);
		updateslider (inertia, slinertia);
		updateslider (nfilters, slpasses);
		updateslider (curcutoff, slcurcutoff);
		updateslider (attack, knobAttack);
		updateslider (decay, knobDecay);
		updateslider (sustain, knobSustain);
		updateslider (release, knobRelease);
		default:
			printf("Object Changed: %d\n", idx);
			break;
	}
#undef updateslider
}

void editor::parentHierarchyChanged()
{
	Image &icon= *ImageCache::getFromMemory(about::icon_png, about::icon_pngSize);
	ComponentPeer *peer= getPeer();
	if(peer)
		peer->setIcon(icon);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="editor" componentName=""
                 parentClasses="public AudioProcessorEditor, public ChangeListener"
                 constructorParams="AudioProcessor *const ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="0" overlayOpacity="0.330000013"
                 fixedSize="0" initialWidth="400" initialHeight="428">
  <BACKGROUND backgroundColour="ff272727"/>
  <GROUPCOMPONENT name="new group" id="e5e178cd242b6420" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="1" pos="8 8 384 112" outlinecol="66ffffff"
                  textcol="ffffffff" title="Oscillators" textpos="33"/>
  <GROUPCOMPONENT name="new group" id="ad99a16746beb177" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="1" pos="8 337 384 80" outlinecol="66ffffff"
                  textcol="ffffffff" title="Output" textpos="33"/>
  <LABEL name="new label" id="49509c28b7b7d12d" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="16 361 56 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <LABEL name="new label" id="155d710d9c4a7bd0" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="16 385 56 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Clip" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="new slider" id="8a7b903812862b6c" memberName="slgain" virtualName=""
          explicitFocusOrder="0" pos="80 361 304 16" bkgcol="868686" textboxtext="ffffffff"
          textboxbkgd="565656" textboxhighlight="409a9aff" textboxoutline="0"
          min="0" max="4" int="0.0001" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="0.3"/>
  <SLIDER name="new slider" id="5f153060103ce45b" memberName="slclip" virtualName=""
          explicitFocusOrder="0" pos="80 385 304 16" bkgcol="868686" textboxtext="ffffffff"
          textboxbkgd="565656" textboxhighlight="409a9aff" textboxoutline="0"
          min="0" max="5" int="0.0001" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="new slider" id="9ed6f0186f5ff937" memberName="slsaw" virtualName=""
          explicitFocusOrder="0" pos="24 48 40 40" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="eb3d9855455c7a5c" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="24 88 40 16" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Saw" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="f984b6ce867a512c" memberName="slrect" virtualName=""
          explicitFocusOrder="0" pos="72 48 40 40" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="4df8bd0f758110b0" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="72 88 40 16" textCol="ffffffff" edTextCol="ff000000"
         edBkgCol="0" labelText="Rect" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="787a4f0997781dd1" memberName="sltri" virtualName=""
          explicitFocusOrder="0" pos="120 48 40 40" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="881dba415f31e105" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="120 88 40 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Tri" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="34b4e27fcd2e1063" memberName="sltune" virtualName=""
          explicitFocusOrder="0" pos="168 48 40 40" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="2466156e2db40baf" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="168 88 40 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Tune" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <GROUPCOMPONENT name="new group" id="7ce402f8c62d5932" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="1" pos="8 129 384 200" outlinecol="66ffffff"
                  textcol="ffffffff" title="Filter" textpos="33"/>
  <LABEL name="new label" id="e57e597377fef365" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="16 153 64 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Filter X" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="new slider" id="df34f7f508b7adb0" memberName="slcutoff"
          virtualName="" explicitFocusOrder="0" pos="80 153 304 16" bkgcol="868686"
          textboxtext="ffffffff" textboxbkgd="565656" textboxhighlight="409a9aff"
          textboxoutline="0" min="0" max="4" int="0.0001" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="0.5"/>
  <LABEL name="new label" id="e2f509e8c9131813" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="16 177 64 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Resonance" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="new slider" id="35786a165f16578e" memberName="slreso" virtualName=""
          explicitFocusOrder="0" pos="80 177 304 16" bkgcol="868686" textboxtext="ffffffff"
          textboxbkgd="565656" textboxhighlight="409a9aff" textboxoutline="0"
          min="0" max="4" int="0.0001" style="LinearHorizontal" textBoxPos="TextBoxRight"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="0.5"/>
  <LABEL name="new label" id="cefa7252c084bf3a" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="16 201 64 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Bandwidth" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="new slider" id="5362f75ced0b9ac9" memberName="slbandwidth"
          virtualName="" explicitFocusOrder="0" pos="80 201 304 16" bkgcol="868686"
          textboxtext="ffffffff" textboxbkgd="565656" textboxhighlight="409a9aff"
          textboxoutline="0" min="0" max="4" int="0.0001" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="0.5"/>
  <LABEL name="new label" id="adcc1d907bb16758" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="16 225 64 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Passes" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="new slider" id="29e98c8c7765790" memberName="slpasses"
          virtualName="" explicitFocusOrder="0" pos="80 225 304 16" bkgcol="868686"
          textboxtext="ffffffff" textboxbkgd="565656" textboxhighlight="409a9aff"
          textboxoutline="0" min="0" max="4" int="0.0001" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="eae3af57dfc37cd5" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="16 249 64 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Velocity" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="new slider" id="f1f951fe4565a7db" memberName="slvelocity"
          virtualName="" explicitFocusOrder="0" pos="80 249 304 16" bkgcol="868686"
          textboxtext="ffffffff" textboxbkgd="565656" textboxhighlight="409a9aff"
          textboxoutline="0" min="0" max="4" int="0.0001" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="0.5"/>
  <LABEL name="new label" id="145c7f21c5783bd3" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="16 273 64 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Inertia" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="new slider" id="1f326d02c58973a" memberName="slinertia"
          virtualName="" explicitFocusOrder="0" pos="80 273 304 16" bkgcol="868686"
          textboxtext="ffffffff" textboxbkgd="565656" textboxhighlight="409a9aff"
          textboxoutline="0" min="0" max="4" int="0.0001" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="0.5"/>
  <LABEL name="new label" id="77aa4e9b34a8fa81" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="16 297 64 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Filter Freq" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="34"/>
  <SLIDER name="new slider" id="88030f6cab98eb34" memberName="slcurcutoff"
          virtualName="" explicitFocusOrder="0" pos="80 297 304 16" bkgcol="868686"
          textboxtext="ffffffff" textboxbkgd="565656" textboxhighlight="409a9aff"
          textboxoutline="0" min="0" max="4" int="0.0001" style="LinearHorizontal"
          textBoxPos="TextBoxRight" textBoxEditable="1" textBoxWidth="60"
          textBoxHeight="20" skewFactor="0.4"/>
  <LABEL name="new label" id="bf2b92c62f94cc75" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="24 -28Cc 80 16" posRelativeY="9ed6f0186f5ff937"
         textCol="ffffffff" edTextCol="ff000000" edBkgCol="0" labelText="Waveform"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="788f76f9610aa084" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="226 89 32 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="A" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="c5f8428d8d54eb65" memberName="label19" virtualName=""
         explicitFocusOrder="0" pos="720 168 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Inertia" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="e21ba2fabc5b6c77" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="664 168 56 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Velocity" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="d263507c08f0e588" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="266 89 32 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="D" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="1a960ef97d83f53a" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="306 89 32 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="S" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8a53fb5fd12f582b" memberName="label18" virtualName=""
         explicitFocusOrder="0" pos="346 89 32 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="R" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="e34f9594ade717e" memberName="slattack5"
          virtualName="" explicitFocusOrder="0" pos="672 136 40 32" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="fccef4f71bc5a237" memberName="slattack6"
          virtualName="" explicitFocusOrder="0" pos="728 136 32 32" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="9c19403fd33058bb" memberName="label21" virtualName=""
         explicitFocusOrder="0" pos="616 168 48 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Scale" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="94d601be4e7bf89b" memberName="label22" virtualName=""
         explicitFocusOrder="0" pos="224 32 136 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Envelope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="9c6a0f0cb6d7c451" memberName="slattack7"
          virtualName="" explicitFocusOrder="0" pos="624 136 32 32" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="9b7cc6b66815757b" memberName="knobAttack"
          virtualName="" explicitFocusOrder="0" pos="226 48 32 41" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="dbcf879a8e4f456b" memberName="knobDecay"
          virtualName="" explicitFocusOrder="0" pos="266 48 32 41" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="ba560858e5b507f3" memberName="knobSustain"
          virtualName="" explicitFocusOrder="0" pos="306 48 32 41" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="89e012ddb565692c" memberName="knobRelease"
          virtualName="" explicitFocusOrder="0" pos="346 48 32 41" thumbcol="ffbbf2ff"
          rotarysliderfill="7f00b9ff" rotaryslideroutline="80ffffff" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
