#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

#include "console_default.h"
#include "logic.h"
#include "jigsaw.h"

#define ROW 5
#define COL 5

#define MAX_LEVEL 1
#define MAX_LIFE ((ROW) % 2 ? (ROW) / 2 : (ROW) / 2 - 1)

void Init();
void InitScript();
bool Fail();

HANDLE hIn, hOut;
HWND hWnd;
RECT MouseRect;

int screenx, screeny;

int Level = 1;
int Life = MAX_LIFE;

int main()
{
	// DWORD fdwSaveOldMode;
	DWORD dw;
	DWORD fdwMode;
	INPUT_RECORD Rec[1024];
	int x, y;

	Init();
	InitScript();

	fdwMode = ENABLE_EXTENDED_FLAGS;
	SetConsoleMode(hIn, fdwMode);
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(hIn, fdwMode);

	int* answers[] = {
		(int*)malloc(sizeof(int) * 3),
		(int*)malloc(sizeof(int) * 3)
	};
	ItemInfo* items = placeItems(screenx, screeny, answers);

	for (int i = 0; i < 10; i++) {
		gotoxy(items[i].x, items[i].y);
		printf(items[i].name);
	}

	int clicked[3] = {-1, -1, -1};
	while (true) {
		ReadConsoleInput(hIn, Rec, 1024, &dw);

		for (int i = 0; i < 1024; i++) {
			if (Rec[i].EventType == MOUSE_EVENT
				&& (Rec[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
				x = Rec[i].Event.MouseEvent.dwMousePosition.X;
				y = Rec[i].Event.MouseEvent.dwMousePosition.Y;

				gotoxy(0, 2);
				for (int j = 0; j < 10; j++) {
					ItemInfo item = items[j];
					int itemY = item.y;
					int itemXMin = item.x;
					int itemXMax = item.x + strlen(item.name);
				
					if (itemY == y && itemXMin <= x && x <= itemXMax) {
						if (clicked[0] == -1) {
							clicked[0] = item.no;
						}
						else if (clicked[1] == -1) {
							clicked[1] = item.no;
						}
						else if (clicked[2] == -1) {
							clicked[2] = item.no;

							for (int k = 0; k < 2; k++) {
								int* answer = answers[k];
								int _i;

								for (_i = 0; _i < 3; _i++) {
									if (answer[_i] != clicked[_i]) {
										if(!Fail())
											goto endGame;
										goto L1;
									}
								}
								if (_i == 3)
									goto endGame;
							}
						L1:
							for (int k = 0; k < 3; k++) {
								clicked[k] = -1;
							}
						}

						break;
					}
				}
			}
		}
	}
endGame:
	ClipCursor(NULL);

	return 0;
}

void Init()
{
	COORD Coord;
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	hWnd = GetConsoleWindow();

	set_cursor_type(false);
	set_output_color(0x07);
	system("cls");

	SetConsoleDisplayMode(hOut, 1, &Coord);
	GetConsoleScreenBufferInfo(hOut, &SBInfo);
	screenx = SBInfo.srWindow.Right;
	screeny = SBInfo.srWindow.Bottom;
	resize_console(SBInfo.srWindow.Right, SBInfo.srWindow.Bottom);

	GetClientRect(hWnd, &MouseRect);
	ClientToScreen(hWnd, (LPPOINT)&MouseRect);
	ClientToScreen(hWnd, (LPPOINT)&MouseRect.right);
	ClipCursor(&MouseRect);
}

void InitScript()
{
	char *Scripts[] = {
		"너는 평소 마우스를 소중히 여기지 않았찌!",
		"게임 하나 할까?",
		"지금부터 이곳에 놓인 도구들 중 적절히 3가지를 조합해 이곳을 탈출하도록.",
		"단, 잘못된 조합을 고르면 그 대가를 치르게 될 것이다.",
		"살든지 죽든지, 선택은 자네 몫이야.",
		"게임을 시작하지.",
	};

	set_output_color(0x0c);
	for (int i = 0; i < sizeof(Scripts) / sizeof(Scripts[0]); i++) {
		printf("???: ");
		puts(Scripts[i]);
		_getch();
		system("cls");
	}
	set_output_color(0x07);
}

bool Fail()
{
	static int div = ROW;

	if (Life > 0) {
		InflateRect(&MouseRect, -(MouseRect.right - MouseRect.left) / div,
			-(MouseRect.bottom - MouseRect.top) / div);
		ClipCursor(&MouseRect);

		Life--;
		div -= 2;

		return true;
	}

	set_output_color(0x07);
	system("cls");
	set_output_color(0x0c);
	puts("???: 게임 오버.");
	set_output_color(0x07);
	_getch();
	system("cls");
	printJigsaw(30);

	return false;
}