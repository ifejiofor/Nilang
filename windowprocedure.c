/*
 * windowprocedure.c
 * Definition of the window procedure for Nilang
 */

#include <windows.h>
#include "windowprocedure.h"


LRESULT CALLBACK PrimaryWindowProcedure(HWND window, UINT messageCode, WPARAM wParam, LPARAM lParam) {
    return DefWindowProc(window, messageCode, wParam, lParam);
}