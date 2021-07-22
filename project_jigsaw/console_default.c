#include "console_default.h"
#include <Windows.h>

// Move cursor to specific point.
void gotoxy(short x, short y)
{
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// Get cursor's x-axis position.
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

// Get cursor's y-axis position.
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

// Set output text and background color.
void set_output_color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Set cursor visibility.
void set_cursor_type(bool bShow)
{
	CONSOLE_CURSOR_INFO CurInfo;

	CurInfo.dwSize = (bShow) ? 20 : 1;
	CurInfo.bVisible = bShow;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

// Resize console screen to specific size.
void resize_console(short nWidth, short nHeight)
{
	HANDLE hOut;
	COORD tmp = { 255, 255 };
	COORD size = { nWidth, nHeight };
	SMALL_RECT sr = { 0, 0, nWidth - 1, nHeight - 1 };

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hOut, tmp);
	SetConsoleWindowInfo(hOut, TRUE, &sr);
	SetConsoleScreenBufferSize(hOut, size);
}