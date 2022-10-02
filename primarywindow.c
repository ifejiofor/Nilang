/*
 * primarywindow.c
 * Implementations of functions relating to the primary window of Nilang
 */

#include <windows.h>
#include "primarywindow.h"
#include "primarywindowprocedure.h"
#include "errorhandler.h"
#include "drawingfunctions.h"
#include "globalconstants.h"


static WORD InitializeAsPrimaryWindowClass(WNDCLASS *pointerToWindowClass, HINSTANCE currentInstance) {
    pointerToWindowClass->style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    pointerToWindowClass->lpfnWndProc = PrimaryWindowProcedure;
    pointerToWindowClass->cbClsExtra = 0;
    pointerToWindowClass->cbWndExtra = 0;
    pointerToWindowClass->hInstance = currentInstance;
    pointerToWindowClass->hIcon = LoadIcon(NULL, IDI_APPLICATION);
    pointerToWindowClass->hCursor = LoadCursor(NULL, IDC_ARROW);
    pointerToWindowClass->hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);
    pointerToWindowClass->lpszMenuName = NULL;
    pointerToWindowClass->lpszClassName = NAME_OF_PRIMARY_WINDOW_CLASS;

    return !STATUS_CODE_FOR_FAILURE;
}


HWND CreatePrimaryWindow(HINSTANCE currentInstance) {
    WORD initializationStatus, registrationStatus;
    WNDCLASS windowClass;

    initializationStatus = InitializeAsPrimaryWindowClass(&windowClass, currentInstance);

    if (initializationStatus == STATUS_CODE_FOR_FAILURE) {
        PerformErrorHandling(WINDOW_CLASS_INITIALIZATION_FAILED);
        return NULL;
    }

    registrationStatus = RegisterClass(&windowClass);

    if (registrationStatus == STATUS_CODE_FOR_FAILURE) {
        PerformErrorHandling(WINDOW_CLASS_REGISTRATION_FAILED);
        return NULL;
    }

    return CreateWindow(NAME_OF_PRIMARY_WINDOW_CLASS, CAPTION_OF_PRIMARY_WINDOW,
        WS_OVERLAPPEDWINDOW | WS_VSCROLL, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, NULL, currentInstance, NULL);
}


void PaintAsPrimaryWindow(HWND window) {
    HDC deviceContext;
    PAINTSTRUCT paintStructure;

    deviceContext = BeginPaint(window, &paintStructure);
    DrawLineNumbers(window, deviceContext, &paintStructure.rcPaint);
    EndPaint(window, &paintStructure);
}