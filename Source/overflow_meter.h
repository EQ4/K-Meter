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

#ifndef __OVERFLOW_METER_H__
#define __OVERFLOW_METER_H__

#include "JuceHeader.h"
#include "common/widgets/generic_state_label.h"



//==============================================================================
/**
*/
class OverflowMeter : public GenericStateLabel
{
public:
    OverflowMeter(const String &componentName);
    ~OverflowMeter();

    void setOverflows(int Overflows);

private:
    JUCE_LEAK_DETECTOR(OverflowMeter);

    int nOverflows;
};


#endif  // __OVERFLOW_METER_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:
