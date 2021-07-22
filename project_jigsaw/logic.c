#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANDINT(a, b) ((rand() % ((b) - (a))) + (a))

/*
 * 정답
 *   + AA건전지, 라디오, 안테나
 *   + 사랑의빳데리, 핸드폰, 마이크로심
 * 안 쓰는 것들
 *   + 종이컵, 콜라, 치토스, 나노심, 직박구리폴더
 */

/*
 *
 * struct
 *
 */
#ifndef _ITEMINFO_STRUCT
#define _ITEMINFO_STRUCT
typedef struct {
	int no;
	int x;
	int y;
	const char* name;
} ItemInfo;
#endif


/*
 *
 * unique rand
 *
 */
int randIndex = 0, *randHistory = NULL;
int contains(int* arr, int len, int target) {
	for (int i = 0; i < len; i++) {
		if (*(arr + i) == target)
			return 1;
	}
	return 0;
}
void initUniqueRand(int historyLimit) {
	if (randHistory != NULL)
		free(randHistory);
	randHistory = (int*)malloc(sizeof(int) * historyLimit);
	randIndex = 0;
}
int uniqueRandIntHelper(int a, int b) {
	int r;
	while(1) {
		r = RANDINT(a, b);
		if (!contains(randHistory, randIndex, r)) {
			randHistory[randIndex] = r;
			randIndex++;
			return r;
		}
	}
}
int uniqueRandInt(int b) {
	return uniqueRandIntHelper(0, b);
}

/*
 *
 * logic about area
 *
 */
int area_horizontal_index(int an, int r) {
	if (0 < an && an < r)
		return an;
	else if (r <= an && an < r * 2 - 1)
		return r - 1;
	else if (r * 2 - 1 <= an && an <= r * 3 - 3)
		return r - (an - (r * 2 - 3));
	else
		return 0;
}
int area_vertical_index(int an, int r) {
	if (0 < an && an < r)
		return 0;
	else if (r <= an && an < r * 2 - 1)
		return an - (r - 1);
	else if (r * 2 <= an && an <= r * 3 - 2)
		return r - 1;
	else
		return r - 1 - (an - (r * 3 - 3));
}

/*
 *
 * logic
 *
 */
const char* itemNames[] = {
	"AA건전지",
	"라디오",
	"안테나",
	"사랑의빳데리",
	"핸드폰",
	"마이크로심",
	"안 쓰는 것들"
	"종이컵",
	"콜라",
	"나노심",
	"직박구리폴더"
};

ItemInfo* placeItems(int width, int height, int** answers) {
	 // 정답 만들기
	initUniqueRand(3);
	for (int i = 0; i < 3; i++)
		answers[0][i] = i;
	initUniqueRand(3);
	for (int i = 0; i < 3; i++)
		answers[1][i] = 3 + i;

	srand((unsigned)time(NULL));
	
	// 아이템 위치배치
	ItemInfo* items = (ItemInfo*)malloc(sizeof(ItemInfo) * 10);

	int areaWUnit = width / 5,
		areaHUnit = height / 5,
		itemIndex = 0;

	initUniqueRand(4);
	for (int i = 0; i < 4; i++) {
		int area = uniqueRandInt(16);
		int xi = area_horizontal_index(area, 5),
			yi = area_vertical_index(area, 5),
		    x = RANDINT(areaWUnit * i, areaWUnit * (i + 1)),
			y = RANDINT(areaHUnit * i, areaHUnit * (i + 1));
		items[itemIndex].x = x;
		items[itemIndex].y = y;
		itemIndex++;
	}
	initUniqueRand(4);
	for (int i = 0; i < 4; i++) {
		int area = uniqueRandInt(8);
		int xi = area_horizontal_index(area, 3),
			yi = area_vertical_index(area, 3),
			x = areaWUnit + RANDINT(areaWUnit * i, areaWUnit * (i + 1)),
			y = areaHUnit + RANDINT(areaHUnit * i, areaHUnit * (i + 1));
		items[itemIndex].x = x;
		items[itemIndex].y = y;
		itemIndex++;
	}
	{
		int x = areaWUnit + RANDINT(areaWUnit * 2, areaWUnit * 3),
			y = areaHUnit + RANDINT(areaHUnit * 2, areaHUnit * 3);
		items[itemIndex].x = x;
		items[itemIndex].y = y;
		itemIndex++; 
	}
	{
		int x = RANDINT(0, width),
			y = RANDINT(0, height);
		items[itemIndex].x = x;
		items[itemIndex].y = y;
		itemIndex++; 
	}

	// 아이템배정
	initUniqueRand(10);
	for (int i = 0; i < 10; i++) {
		items[i].no = uniqueRandInt(10);
		items[i].name = itemNames[items[i].no];
	}

	return items;
}