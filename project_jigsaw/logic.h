#pragma once
#ifndef _ITEMINFO_STRUCT
#define _ITEMINFO_STRUCT
typedef struct {
	int no;
	int x;
	int y;
	const char* name;
} ItemInfo;
#endif

ItemInfo* placeItems(int width, int height, int** answers);