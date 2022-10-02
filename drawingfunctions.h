/*
 * drawingfunctions.h
 * Prototypes of functions used for drawing in Nilang
 */

#ifndef DRAWINGFUNCTIONS_H
#define DRAWINGFUNCTIONS_H

#include <windows.h>

// Draws line numbers along the left side of a specified window using a specified device context
// This function draws only line numbers whose positions fall within a specified clipping rectangle
void DrawLineNumbers(HWND window, HDC deviceContext, const RECT *clippingRectangle);

#endif // DRAWINGFUNCTIONS_H