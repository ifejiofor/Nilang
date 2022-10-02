/*
 * drawingfunctions.c
 * Implementations of functions used for drawing in Nilang
 */

#include <windows.h>
#include "drawingfunctions.h"
#include "font.h"
#include "globalconstants.h"


static LONG DetermineFirstLineNumberToDraw(const RECT *clippingRectangle, LONG heightOfFont) {
    LONG firstLineNumberToDraw;
    
    if (clippingRectangle == NULL) {
        firstLineNumberToDraw = MINIMUM_LINE_NUMBER;
    }
    else {
        firstLineNumberToDraw = MINIMUM_LINE_NUMBER + clippingRectangle->top / heightOfFont;
    }
    
    return firstLineNumberToDraw;
}


static LONG DetermineLastLineNumberToDraw(const RECT *clippingRectangle, LONG heightOfFont) {
    LONG lastLineNumberToDraw;
    
    if (clippingRectangle == NULL) {
        lastLineNumberToDraw = MAXIMUM_LINE_NUMBER;
    }
    else {
        lastLineNumberToDraw =
            min(MAXIMUM_LINE_NUMBER, MINIMUM_LINE_NUMBER + clippingRectangle->bottom / heightOfFont);
    }
    
    return lastLineNumberToDraw;
}


void DrawLineNumbers(HWND window, HDC deviceContext, const RECT *clippingRectangle) {
    TCHAR buffer[CHARACTER_COUNT_OF_MAXIMUM_LINE_NUMBER + 1];
    POINT position = {0, 0};
    LONG heightOfFont = GetHeightOfFont(window);
    LONG firstLineNumberToDraw = DetermineFirstLineNumberToDraw(clippingRectangle, heightOfFont);
    LONG lastLineNumberToDraw = DetermineLastLineNumberToDraw(clippingRectangle, heightOfFont);

    for (int lineNumber = firstLineNumberToDraw; lineNumber <= lastLineNumberToDraw; lineNumber++) {
        wsprintf(buffer, TEXT("%d"), lineNumber);
        position.y = (lineNumber - MINIMUM_LINE_NUMBER) * heightOfFont;
        TextOut(deviceContext, position.x, position.y, buffer, lstrlen(buffer));
    }
}