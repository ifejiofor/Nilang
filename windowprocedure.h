/*
 * windowprocedure.h
 * Function prototype of the window procedure for Nilang
 */

#ifndef WINDOWPROCEDURE_H
#define WINDOWPROCEDURE_H

#include <windows.h>

LRESULT CALLBACK PrimaryWindowProcedure(HWND window, UINT messageCode, WPARAM wParam, LPARAM lParam);

#endif