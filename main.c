/*
 * main.c
 * Implementation of the "WinMain" of Nilang
 */

#include <windows.h>
#include "primarywindow.h"
#include "errorhandler.h"
#include "globalconstants.h"


int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE previousInstance, LPTSTR commandLine, int commandShow) {
    HWND primaryWindow;
    MSG message;

    primaryWindow = CreatePrimaryWindow(currentInstance);

    if (primaryWindow == NULL) {
        PerformErrorHandling(WINDOW_CREATION_FAILED);
        return 1;
    }

    ShowWindow(primaryWindow, commandShow);

    while (GetMessage(&message, NULL, 0, 0) != 0) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return message.wParam;
}