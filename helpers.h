/*
 * helpers.h
 * Macro definitions and function prototypes for helpers.c
 */

#ifndef HELPERS_H
#define HELPERS_H

#include <windows.h>

#define FAILURE 0
#define SUCCESS 1

#define NAME_OF_PRIMARY_WINDOW_CLASS       TEXT("NilangPrimaryWindowClass")
#define NAME_OF_PRIMARY_WINDOW             TEXT("Nilang - Learn Nigerian languages")
#define NAME_OF_ERROR_WINDOW               TEXT("Error")
#define WINDOW_CLASS_INITIALIZATION_FAILED TEXT("Window class initialization is not successful.")
#define WINDOW_CLASS_REGISTRATION_FAILED   TEXT("Window class registration is not successful.")
#define WINDOW_CREATION_FAILED             TEXT("Window creation is not successful.")


// Performs error handling
void PerformErrorHandling(LPCTSTR errorMessage, HWND parentWindow);

// Returns handle to the created window if successful; returns NULL otherwise
HWND CreatePrimaryWindow(HINSTANCE currentInstance);

// Returns SUCCESS (defined as a non-zero value) if successful; returns FAILURE (defined as zero) otherwise
int InitializePrimaryWindowClass(WNDCLASS * pointerToPrimaryWindowClass, HINSTANCE currentInstance);

#endif // HELPERS_H