/* ----------------------------------------------------------------------------

   K-Meter
   =======
   Implementation of a K-System meter according to Bob Katz' specifications

   Copyright (c) 2010-2015 Martin Zuther (http://www.mzuther.de/)

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   Thank you for using free software!

---------------------------------------------------------------------------- */

#ifndef __PLUGINEDITOR_KMETER_H__
#define __PLUGINEDITOR_KMETER_H__

#include "JuceHeader.h"
#include "plugin_processor.h"
#include "kmeter.h"
#include "skin.h"
#include "window_validation.h"
#include "common/widgets/generic_horizontal_meter.h"
#include "common/widgets/generic_window_about.h"
#include "common/widgets/generic_window_skin.h"


//==============================================================================
/**
*/
class KmeterAudioProcessorEditor : public AudioProcessorEditor, public ButtonListener, public ActionListener
{
public:
    KmeterAudioProcessorEditor(KmeterAudioProcessor *ownerFilter, int nNumChannels);
    ~KmeterAudioProcessorEditor();

    void buttonClicked(Button *button);
    void actionListenerCallback(const String &message);
    void updateParameter(int nIndex);

    //==============================================================================
    // This is just a standard Juce paint method...
    void paint(Graphics &g);
    void resized();

private:
    JUCE_LEAK_DETECTOR(KmeterAudioProcessorEditor);

    void reloadMeters();
    void applySkin();
    void loadSkin();
    void updateAverageAlgorithm(bool reload_meters);

    bool bReloadMeters;
    bool bIsValidating;
    bool bValidateWindow;
    bool bInitialising;
    bool bExpanded;
    bool bDisplayPeakMeter;

    int nCrestFactor;
    int nInputChannels;
    int nStereoInputChannels;

    File fileSkinDirectory;
    Skin skin;
    String strSkinName;

    KmeterAudioProcessor *pProcessor;
    ScopedPointer<Kmeter> kmeter;
    ScopedPointer<GenericHorizontalMeter> stereoMeter;
    ScopedPointer<GenericHorizontalMeter> phaseCorrelationMeter;

    ImageButton ButtonK20;
    ImageButton ButtonK14;
    ImageButton ButtonK12;
    ImageButton ButtonNormal;

    ImageButton ButtonItuBs1770;
    ImageButton ButtonRms;

    ImageButton ButtonExpanded;
    ImageButton ButtonSkin;
    ImageButton ButtonDisplayPeakMeter;
    ImageButton ButtonInfinitePeakHold;
    ImageButton ButtonReset;

    ImageButton ButtonMono;
    ImageButton ButtonValidation;
    ImageButton ButtonAbout;

#ifdef DEBUG
    ImageComponent LabelDebug;
#endif

    ImageComponent BackgroundImage;
};


#endif  // __PLUGINEDITOR_KMETER_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:
