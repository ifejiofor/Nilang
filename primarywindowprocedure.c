/*
 * primarywindowprocedure.c
 * Implementation of the primary window procedure of Nilang
 */

#include <windows.h>
#include "primarywindowprocedure.h"
#include "primarywindow.h"
#include "verticalscrollbar.h"


LRESULT CALLBACK PrimaryWindowProcedure(HWND window, UINT messageCode, WPARAM wParam, LPARAM lParam) {
    switch (messageCode) {
        case WM_CREATE:
            InitializeVerticalScrollBar(window);
            return 0;

        case WM_PAINT:
            PaintAsPrimaryWindow(window);
            return 0;

        case WM_SIZE:
            UpdateHeightOfVerticalScrollBar(window, HIWORD(lParam));
            return 0;

        case WM_VSCROLL:
            PerformVerticalScrolling(window, LOWORD(wParam), HIWORD(wParam));
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(window, messageCode, wParam, lParam);
    }
}