/*
 * primarywindowprocedure.h
 * Prototype of the primary window procedure of Nilang
 */

#ifndef PRIMARYWINDOWPROCEDURE_H
#define PRIMARYWINDOWPROCEDURE_H

#include <windows.h>

LRESULT CALLBACK PrimaryWindowProcedure(HWND window, UINT messageCode, WPARAM wParam, LPARAM lParam);

#endif // PRIMARYWINDOWPROCEDURE_H