/*
 * main.c
 * Definition of "WinMain" for Nilang
 */

#include <windows.h>
#include "helpers.h"


int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE previousInstance, LPTSTR commandLine, int commandShow) {
    HWND primaryWindow;
    MSG message;

    primaryWindow = CreatePrimaryWindow(currentInstance);

    if (primaryWindow == NULL) {
        PerformErrorHandling(WINDOW_CREATION_FAILED, NULL);
        return 1;
    }

    ShowWindow(primaryWindow, commandShow);

    while (GetMessage(&message, NULL, 0, 0) != 0) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return message.wParam;
}