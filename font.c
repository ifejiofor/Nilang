/*
 * font.c
 * Implementations of font-related functions of Nilang
 */

#include <windows.h>
#include "font.h"
#include "globalconstants.h"


LONG GetHeightOfFont(HWND window) {
    HDC deviceContext;
    BOOL textMetricsStatus;
    TEXTMETRIC textMetrics;
    LONG heightOfFont;
    
    deviceContext = GetDC(window);
    textMetricsStatus = GetTextMetrics(deviceContext, &textMetrics);
    
    if (textMetricsStatus == STATUS_CODE_FOR_FAILURE) {
        heightOfFont = DEFAULT_HEIGHT_OF_FONT;
    }
    else {
        heightOfFont = textMetrics.tmHeight + textMetrics.tmExternalLeading;
    }
    
    ReleaseDC(window, deviceContext);
    return heightOfFont;
}