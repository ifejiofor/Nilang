/*
 * verticalscrollbar.h
 * Prototypes of vertical scroll bar-related functions of Nilang
 */

#ifndef VERTICALSCROLLBAR_H
#define VERTICALSCROLLBAR_H

#include <windows.h>

// Initializes the vertical scroll bar of a specified window
void InitializeVerticalScrollBar(HWND window);

// Updates the height of the vertical scroll bar of a specified window
void UpdateHeightOfVerticalScrollBar(HWND window, WORD newHeight);

// Returns the height of one unit of vertical scrolling in a specified window
UINT GetHeightOfOneUnitOfVerticalScrolling(HWND window);

// Returns the count of vertical scroll positions that make one "line" in a specified window
int GetCountOfVerticalScrollPositionsThatMakeOneLine(HWND window);

// Returns the page size of the vertical scroll bar of a specified window
int GetPageSizeOfVerticalScrollBar(HWND window);

// Returns the position of the vertical scroll thumb of a specified window
int GetPositionOfVerticalScrollThumb(HWND window);

// Performs vertical scrolling of a specified window in line with a specified scroll code
void PerformVerticalScrolling(HWND window, WORD scrollCode, WORD trackedPositionOfScrollThumb);

#endif // VERTICALSCROLLBAR_H