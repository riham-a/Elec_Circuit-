/* 
See "version.h" for version info and copyright information
This file was last modified on 05.16.1999
*/
 
#ifndef AUXILIARY_H
#define AUXILIARY_H
#include <cstdlib>
#include <windows.h>
#include "C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\um\timeapi.h"
#include "version.h"

// Pause for iTime milliseconds
void Pause(const unsigned long ulTime);

// Return the number of milliseconds since Windows was started
unsigned long CurrentTime();

// Return true if iInterval milliseconds have elapsed since
// the last time ElapsedTime was called.  Returns false on the 
// first call
bool ElapsedTime(const unsigned long ulInterval);

#endif //AUXILIARY_H