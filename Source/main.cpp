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

// build stand-alone application for plugin
#ifdef KMETER_STAND_ALONE

#include "standalone_application.h"

START_JUCE_APPLICATION(KmeterStandalone)

#endif

// build VST plugin
#if defined (KMETER_VST_PLUGIN) || defined (KMETER_LV2_PLUGIN)

// do nothing till you hear from me...

#endif


// Local Variables:
// ispell-local-dictionary: "british"
// End:
