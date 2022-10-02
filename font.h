/*
 * font.h
 * Prototypes of font-related functions of Nilang
 */

#ifndef FONT_H
#define FONT_H

#include <windows.h>

// Returns the height of font, in logical units, for a specified window
LONG GetHeightOfFont(HWND window);

#endif // FONT_H