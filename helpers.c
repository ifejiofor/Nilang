/*
 * helpers.c
 * Definitions of helper functions for Nilang
 */

#include <windows.h>
#include "windowprocedure.h"
#include "helpers.h"


void PerformErrorHandling(LPCTSTR errorMessage, HWND parentWindow) {
   MessageBox(parentWindow, errorMessage, NAME_OF_ERROR_WINDOW, MB_ICONERROR | MB_OK);
   // TODO: Log error in log file.
}


HWND CreatePrimaryWindow(HINSTANCE currentInstance) {
    int initializationStatus, registrationStatus;
    WNDCLASS primaryWindowClass;

    initializationStatus = InitializePrimaryWindowClass(&primaryWindowClass, currentInstance);

    if (initializationStatus == FAILURE) {
        PerformErrorHandling(WINDOW_CLASS_INITIALIZATION_FAILED, NULL);
        return NULL;
    }

    registrationStatus = RegisterClass(&primaryWindowClass);

    if (registrationStatus == FAILURE) {
        PerformErrorHandling(WINDOW_CLASS_REGISTRATION_FAILED, NULL);
        return NULL;
    }

    return CreateWindow(NAME_OF_PRIMARY_WINDOW_CLASS, NAME_OF_PRIMARY_WINDOW, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, currentInstance, NULL);
}


int InitializePrimaryWindowClass(WNDCLASS * pointerToPrimaryWindowClass, HINSTANCE currentInstance) {
    pointerToPrimaryWindowClass->style = CS_HREDRAW | CS_VREDRAW;
    pointerToPrimaryWindowClass->lpfnWndProc = PrimaryWindowProcedure;
    pointerToPrimaryWindowClass->cbClsExtra = 0;
    pointerToPrimaryWindowClass->cbWndExtra = 0;
    pointerToPrimaryWindowClass->hInstance = currentInstance;
    pointerToPrimaryWindowClass->hIcon = LoadIcon(NULL, IDI_APPLICATION);
    pointerToPrimaryWindowClass->hCursor = LoadCursor(NULL, IDC_ARROW);
    pointerToPrimaryWindowClass->hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    pointerToPrimaryWindowClass->lpszMenuName = NULL;
    pointerToPrimaryWindowClass->lpszClassName = NAME_OF_PRIMARY_WINDOW_CLASS;

    return SUCCESS;
}