/* ----------------------------------------------------------------------------

   MZ common JUCE
   ==============
   Common classes for use with the JUCE library

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

#ifndef __GENERIC_METER_SEGMENT_H__
#define __GENERIC_METER_SEGMENT_H__

#include "JuceHeader.h"


/// Meter segment component.  This widget consists of a coloured
/// filled rectangle (meter segment) surrounded by a small coloured
/// rectangle (peak marker).  Both rectangles react to level changes
/// with a change in colour or visibility.
///
/// @see GenericMeterBar
///
class GenericMeterSegment : public Component
{
public:
    GenericMeterSegment(float lowerThresholdNew = -144.0f, float thresholdRangeNew = 1.0f, bool isTopmostNew = false);
    ~GenericMeterSegment();

    float setThresholds(float lowerThresholdNew, float thresholdRangeNew, bool isTopmostNew);
    void setColour(float segmentHueNew, const Colour &colPeakMarkerNew);

    void setNormalLevels(float normalLevelNew, float normalLevelPeakNew);
    void setDiscreteLevels(float discreteLevelNew, float discreteLevelPeakNew);
    void setLevels(float normalLevelNew, float discreteLevelNew, float normalLevelPeakNew, float discreteLevelPeakNew);

    void paint(Graphics &g);
    void resized();
    void visibilityChanged();

private:
    JUCE_LEAK_DETECTOR(GenericMeterSegment);

    Colour colPeakMarker;

    float segmentHue;
    float segmentBrightness;
    float outlineBrightness;

    float lowerThreshold;
    float upperThreshold;
    float thresholdRange;

    bool lightPeakMarker;
    bool isTopmost;
};


#endif  // __GENERIC_METER_SEGMENT_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:
