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

#ifndef __METER_BAR_H__
#define __METER_BAR_H__

#include "JuceHeader.h"
#include "common/widgets/generic_meter_bar.h"


//==============================================================================
/**
*/
class MeterBar : public GenericMeterBar
{
public:
    MeterBar();
    ~MeterBar();

    void create(int crestFactor, bool bExpanded, Orientation orientation, int nMainSegmentHeight);

private:
    JUCE_LEAK_DETECTOR(MeterBar);

    Array<float> arrHues;
};


#endif  // __METER_BAR_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:
