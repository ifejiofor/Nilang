/*
 * verticalscrollbar.c
 * Implementations of vertical scroll bar-related functions of Nilang
 */

#include <windows.h>
#include "verticalscrollbar.h"
#include "font.h"
#include "globalconstants.h"


static BOOL ScrollCodeShouldBeProcessed(WORD scrollCode) {
    return scrollCode == SB_THUMBTRACK || scrollCode == SB_LINEDOWN || scrollCode == SB_LINEUP ||
        scrollCode == SB_PAGEDOWN || scrollCode == SB_PAGEUP || scrollCode == SB_BOTTOM || scrollCode == SB_TOP;
}


static int CalculatePositionWhereScrollThumbShouldBeMoved(HWND window, int scrollCode,
    int trackedPositionOfScrollThumb)
{
    int formerPosition, newPosition;
    
    switch (scrollCode) {
        case SB_THUMBTRACK:
            newPosition = trackedPositionOfScrollThumb;
            break;
        
        case SB_LINEDOWN:
            formerPosition = GetPositionOfVerticalScrollThumb(window);
            newPosition = formerPosition + GetCountOfVerticalScrollPositionsThatMakeOneLine(window);
            break;

        case SB_LINEUP:
            formerPosition = GetPositionOfVerticalScrollThumb(window);
            newPosition = formerPosition - GetCountOfVerticalScrollPositionsThatMakeOneLine(window);
            break;

        case SB_PAGEDOWN:
            formerPosition = GetPositionOfVerticalScrollThumb(window);
            newPosition = formerPosition + GetPageSizeOfVerticalScrollBar(window);
            break;

        case SB_PAGEUP:
            formerPosition = GetPositionOfVerticalScrollThumb(window);
            newPosition = formerPosition - GetPageSizeOfVerticalScrollBar(window);
            break;
        
        case SB_BOTTOM:
            newPosition = MAXIMUM_VERTICAL_SCROLL_POSITION;
            break;
        
        case SB_TOP:
            newPosition = MINIMUM_VERTICAL_SCROLL_POSITION;
            break;
    }

    return newPosition;
}


static void MoveVerticalScrollThumb(HWND window, WORD scrollCode, WORD trackedPositionOfScrollThumb) {
    int calculatedPosition;
    SCROLLINFO scrollInformation;
    
    calculatedPosition =
        CalculatePositionWhereScrollThumbShouldBeMoved(window, scrollCode, trackedPositionOfScrollThumb);

    scrollInformation.cbSize = sizeof(SCROLLINFO);
    scrollInformation.fMask = SIF_POS;
    scrollInformation.nPos = calculatedPosition;

    SetScrollInfo(window, SB_VERT, &scrollInformation, TRUE);
}


static void ScrollWindowClientAreaVertically(HWND window, int amountOfVerticalScrolling) {
    HDC deviceContext;
    
    ScrollWindowEx(window, 0, amountOfVerticalScrolling, NULL, NULL, NULL, NULL,
        SW_INVALIDATE | SW_ERASE | SW_SCROLLCHILDREN);
    
    deviceContext = GetDC(window);
    OffsetViewportOrgEx(deviceContext, 0, amountOfVerticalScrolling, NULL);
    ReleaseDC(window, deviceContext);

    UpdateWindow(window);
}


void InitializeVerticalScrollBar(HWND window) {
    SCROLLINFO scrollInformation;

    scrollInformation.cbSize = sizeof(SCROLLINFO);
    scrollInformation.fMask = SIF_RANGE | SIF_POS;
    scrollInformation.nMin = MINIMUM_VERTICAL_SCROLL_POSITION;
    scrollInformation.nMax = MAXIMUM_VERTICAL_SCROLL_POSITION; // TODO: Make MAXIMUM_VERTICAL_SCROLL_POSITION dynamic
    scrollInformation.nPos = MINIMUM_VERTICAL_SCROLL_POSITION;

    SetScrollInfo(window, SB_VERT, &scrollInformation, FALSE);
}


void UpdateHeightOfVerticalScrollBar(HWND window, WORD newHeight) {
    SCROLLINFO scrollInformation;

    scrollInformation.cbSize = sizeof(SCROLLINFO);
    scrollInformation.fMask = SIF_PAGE;
    scrollInformation.nPage = newHeight / GetHeightOfOneUnitOfVerticalScrolling(window);

    SetScrollInfo(window, SB_VERT, &scrollInformation, TRUE);
}


UINT GetHeightOfOneUnitOfVerticalScrolling(HWND window) {
    return GetHeightOfFont(window);
}


int GetCountOfVerticalScrollPositionsThatMakeOneLine(HWND window) {
    int lineHeight = GetHeightOfFont(window);
    int unitHeightOfVerticalScrolling = GetHeightOfOneUnitOfVerticalScrolling(window);

    return lineHeight / unitHeightOfVerticalScrolling;
}


int GetPositionOfVerticalScrollThumb(HWND window) {
    SCROLLINFO scrollInformation = {0};

    scrollInformation.cbSize = sizeof(SCROLLINFO);
    scrollInformation.fMask = SIF_POS;

    GetScrollInfo(window, SB_VERT, &scrollInformation);

    return scrollInformation.nPos;
}


int GetPageSizeOfVerticalScrollBar(HWND window) {
    SCROLLINFO scrollInformation = {0};

    scrollInformation.cbSize = sizeof(SCROLLINFO);
    scrollInformation.fMask = SIF_PAGE;

    GetScrollInfo(window, SB_VERT, &scrollInformation);

    return scrollInformation.nPage;
}


void PerformVerticalScrolling(HWND window, WORD scrollCode, WORD trackedPositionOfScrollThumb) {
    int initialPosition, finalPosition;
    int amountOfVerticalScrolling;

    if (ScrollCodeShouldBeProcessed(scrollCode)) {
        initialPosition = GetPositionOfVerticalScrollThumb(window);
        MoveVerticalScrollThumb(window, scrollCode, trackedPositionOfScrollThumb);
        finalPosition = GetPositionOfVerticalScrollThumb(window);

        amountOfVerticalScrolling = (initialPosition - finalPosition) * GetHeightOfOneUnitOfVerticalScrolling(window);
        ScrollWindowClientAreaVertically(window, amountOfVerticalScrolling);
    }
}