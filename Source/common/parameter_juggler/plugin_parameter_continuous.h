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

#ifndef __PLUGIN_PARAMETER_CONTINUOUS_H__
#define __PLUGIN_PARAMETER_CONTINUOUS_H__

#include "JuceHeader.h"
#include "../mz_juce_common.h"
#include "plugin_parameter.h"


/// Plug-in parameter for storing a floating-point value (continuous
/// values with a given number of decimal places).
///
/// The methods of this class may be called on the audio thread, so
/// they are absolutely time-critical!
///
class PluginParameterContinuous : virtual public PluginParameter
{
public:
    PluginParameterContinuous(float real_minimum, float real_maximum, float real_step_size, float scaling_factor, int decimal_places, bool save_from_deletion = false);
    ~PluginParameterContinuous();

    int getNumberOfSteps();
    float getStepSize();

    virtual void setDefaultRealFloat(float newRealValue, bool updateParameter) override;

    virtual void setFloat(float newValue) override;
    virtual void setRealFloat(float newRealValue) override;

    void setSuffix(const String &newSuffix);

    virtual float getFloatFromText(const String &newValue) override;
    virtual const String getTextFromFloat(float newValue) override;

private:
    JUCE_LEAK_DETECTOR(PluginParameterContinuous);

    float toRealFloat(float newValue);
    float toInternalFloat(float newRealValue);

    float realMinimum;
    float realMaximum;
    float realRange;

    int numberOfSteps;
    int decimalPlaces;
    String valueSuffix;

    bool isNonlinear;
    float scalingFactor;
    float scalingConstantFactor;
};


#endif  // __PLUGIN_PARAMETER_CONTINUOUS_H__


// Local Variables:
// ispell-local-dictionary: "british"
// End:
