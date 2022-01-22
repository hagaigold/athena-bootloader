/* Name: debug_vald.h
 * Author: Stelios Tsampas
 * Copyright: codebender.cc
 * License: GPL http://www.gnu.org/licenses/gpl-2.0.html
 * Project: athena
 * Function: debugging progmem strings
 */

#ifndef debug_vald_h
#define debug_vald_h

#include <avr/pgmspace.h>

#if(DEBUG_VALD > 0)
#undef DBG_VALD
#define DBG_VALD(block) block
#define tracePGMlnVald(msg) tracePGMln(mDebugVald_PREFIX, msg)
const unsigned char mDebugVald_PREFIX[] PROGMEM = "Vald: ";
const unsigned char mDebugVald_VALID[] PROGMEM = "Valid image";
const unsigned char mDebugVald_FAILED[] PROGMEM = "Invalid image";
#endif

#endif
