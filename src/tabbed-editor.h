/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  6 Nov 2010 5:03:05pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_TABBEDEDITOR_TABBEDEDITOR_9B929A4E__
#define __JUCER_HEADER_TABBEDEDITOR_TABBEDEDITOR_9B929A4E__

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
    void setPolyText(String text) { polytext->setText(text, false); }
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);

    // Binary resources:
    static const char* scratches_png;
    static const int scratches_pngSize;

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.

	struct myLookAndFeel: public LookAndFeel
	{
		myLookAndFeel()
		{
			setColour(ComboBox::backgroundColourId, Colour(0xFF101010));
			setColour(ComboBox::textColourId, Colour(0xFFF0F0F0));
			setColour(ComboBox::outlineColourId, Colour(0xFF404040));
			setColour(ComboBox::buttonColourId, Colour(0xFF707070));
			setColour(ComboBox::arrowColourId, Colour(0xFF000000));
			setColour(TextButton::buttonColourId, Colour(0xFF405068));
			setColour(TextButton::textColourOnId, Colour(0xFFFFFFFF));
			setColour(TextButton::textColourOffId, Colour(0xFFFFFFFF));
			setColour(PopupMenu::backgroundColourId, Colour(0xFF404040));
			setColour(PopupMenu::textColourId, Colour(0xFFf0f0f0));
			setColour(PopupMenu::highlightedBackgroundColourId, Colour(0xFF000000));

			LookAndFeel::setDefaultLookAndFeel(this);
		}

		void drawPopupMenuBackground (Graphics& g, int width, int height)
		{
			const Colour background (findColour (PopupMenu::backgroundColourId));
			g.fillAll (background);

			g.setColour (background.overlaidWith (Colour (0x10000000)));
			for (int i = 0; i < height; i += 3)
				g.fillRect (0, i, width, 1);

			g.setColour(Colour(0, 0, 0));
			g.drawRect (0, 0, width, height);
		}

		void drawDocumentWindowTitleBar (DocumentWindow& window,
										 Graphics& g, int w, int h,
										 int titleSpaceX, int titleSpaceW,
										 const Image* icon,
										 bool drawTitleTextOnLeft)
		{
			const bool isActive = window.isActiveWindow();

			g.setGradientFill (ColourGradient (window.getBackgroundColour(),
											   0.0f, 0.0f,
											   window.getBackgroundColour().contrasting (isActive ? 0.15f : 0.05f),
											   0.0f, (float) h, false));
			g.fillAll();

			g.setGradientFill (ColourGradient (Colour(0x40FFFFFF),
											   0.0f, 0.0f,
											   window.getBackgroundColour().withAlpha((uint8)0),
											   0.0f, (float)4, false));
			g.fillRect(0,0, w,4);

			g.setGradientFill (ColourGradient (window.getBackgroundColour().withAlpha((uint8)0),
											   0.0f, h-4,
											   Colour(0x80000000),
											   0.0f, (float)h, false));
			g.fillRect(0,h-4, w,4);


			Font font (h * 0.65f, Font::bold);
			g.setFont (font);

			int textW = font.getStringWidth (window.getName());
			int iconW = 0;
			int iconH = 0;

			if (icon != 0)
			{
				iconH = (int) font.getHeight();
				iconW = icon->getWidth() * iconH / icon->getHeight() + 4;
			}

			textW = jmin (titleSpaceW, textW + iconW);
			int textX = drawTitleTextOnLeft ? titleSpaceX
											: jmax (titleSpaceX, (w - textW) / 2);

			if (textX + textW > titleSpaceX + titleSpaceW)
				textX = titleSpaceX + titleSpaceW - textW;

			if (icon != 0)
			{
				g.setOpacity (isActive ? 1.0f : 0.6f);
				g.drawImageWithin (icon, textX, (h - iconH) / 2, iconW, iconH,
								   RectanglePlacement::centred, false);
				textX += iconW;
				textW -= iconW;
			}

			if (window.isColourSpecified (DocumentWindow::textColourId) || isColourSpecified (DocumentWindow::textColourId))
				g.setColour (findColour (DocumentWindow::textColourId));
			else
				g.setColour (window.getBackgroundColour().contrasting (isActive ? 0.7f : 0.4f));

			g.drawText (window.getName(), textX, 0, textW, h, Justification::centredLeft, true);
		}
	} __myLookAndFeel;

    MidiKeyboardState midi_keyboard_state;
    KeyboardButton *kbd_button;
    //[/UserVariables]

    //==============================================================================
    MidiKeyboardComponent* midi_keyboard;
    TabbedComponent* tabbedEditor;
    PresetComboBox* comboBox;
    Label* polytext;
    Path internalPath1;

    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    tabbed_editor (const tabbed_editor&);
    const tabbed_editor& operator= (const tabbed_editor&);
};


#endif   // __JUCER_HEADER_TABBEDEDITOR_TABBEDEDITOR_9B929A4E__
