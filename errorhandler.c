/*
 * errorhandler.c
 * Implementations of functions that perform error handling for Nilang
 */

#include <windows.h>
#include "errorhandler.h"
#include "globalconstants.h"


void PerformErrorHandling(LPCTSTR errorMessage) {
    MessageBox(NULL, errorMessage, CAPTION_OF_ERROR_MESSAGE_BOX, MB_ICONERROR | MB_OK);
    // TODO: Log the error into a log file
}