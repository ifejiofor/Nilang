/*
 * primarywindow.h
 * Prototypes of functions relating to the primary window of Nilang
 */

#ifndef PRIMARYWINDOW_H
#define PRIMARYWINDOW_H

#include <windows.h>

// Creates the primary window
// If successful, returns the handle of the created window; otherwise, returns NULL
HWND CreatePrimaryWindow(HINSTANCE currentInstance);

// Paints a specified window as the primary window
void PaintAsPrimaryWindow(HWND window);

#endif // PRIMARYWINDOW_H