// 뱀 게임이다!!

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include"Screen.h""

#define TAIL 6

typedef enum _DIRECT{
	LEFT, RIGHT, UP, DOWN
}DIRECT;

typedef struct _POS {
	int nX, nY;			// 좌표
	int nOldX, nOldY;	// 이전좌표
}POS;

// 뱀 구조체 정의
typedef struct _SNAKE {	// 속성들
	int nLife;					//생명 
	DIRECT nDirect;		// 움직일 방향
	clock_t MoveTime;		// 이동시간
	clock_t OldTime;		// 이전 이동시간
	POS sHead;				// 머리의 위치
	POS sTail[20];			// 꼬리의 위치 + 최대 20개
}SNAKE;

SNAKE Snake;

void Move() {
	// step1 : 현재 좌표를 이전 좌표로 복사
	Snake.sHead.nOldX = Snake.sHead.nX;
	Snake.sHead.nOldY = Snake.sHead.nY;

	for (int i = 0; i < TAIL; i++) {
		Snake.sTail[i].nOldX = Snake.sTail[i].nX;
		Snake.sTail[i].nOldY = Snake.sTail[i].nY;
	}

	// step2 : 복사된 이전좌표를 다음 꼬리의 현재좌표에 복사
	// 2-1. 머리의 이전좌표를 첫번째 꼬리의 현재좌표에 복사
	Snake.sTail[0].nX = Snake.sHead.nOldX;
	Snake.sTail[0].nY = Snake.sHead.nOldY;
	// 2-2. 다음 꼬리들에 이전꼬리의 좌표를 복사
	for (int i = 1; i < TAIL; i++) {
		Snake.sTail[i].nX = Snake.sTail[i - 1].nOldX;
		Snake.sTail[i].nY = Snake.sTail[i - 1].nOldY;
	}


}





void init() {

	// Snake 머리 초기화
	Snake.nLife = 1;
	Snake.sHead.nX = 30;
	Snake.sHead.nY = 10;
	Snake.sHead.nOldX = Snake.sHead.nX;
	Snake.sHead.nOldY = Snake.sHead.nY;
	Snake.MoveTime = 100;
	Snake.OldTime = clock();
	Snake.nDirect = LEFT;

	// Snake 꼬리 초기화
	for (int i = 0; i < TAIL; i++) {
		Snake.sTail[i].nX = Snake.sHead.nX + (i + 1) * 2;
		Snake.sTail[i].nY = Snake.sHead.nY;
	}
	
}


void Update() {




	clock_t Curtime = clock();

	if (Curtime - Snake.OldTime > Snake.MoveTime) {
		Snake.OldTime = Curtime;
		switch (Snake.nDirect) {
		case LEFT:
			if (Snake.sHead.nX - 2 > 1) { // 경계에는 들어가지 못한다.
				Move();
				Snake.sHead.nX -= 2;
			}
			break;
		case RIGHT :
			if (Snake.sHead.nX + 2 < 60) {
				Move();
				Snake.sHead.nX += 2;
			}
			break;
		case UP :
			if (Snake.sHead.nY - 1 > 1) { // 머리의 y좌표가 1을 뺏을 때 경계에 해당하는 y좌표인 1보다 작거나 같아지면 실행아니함.
				Move();
				Snake.sHead.nY--;
			}
			break;
		case DOWN:
			if (Snake.sHead.nY + 1 < 20) {
				Move();
				Snake.sHead.nY++;
			}
			break;
		}
	}




}



void Render() {

	ScreenClear();
	//출력코드
	ScreenPrint(Snake.sHead.nX, Snake.sHead.nY, "●");
	for (int i = 0; i < TAIL; i++) {
		ScreenPrint(Snake.sTail[i].nX, Snake.sTail[i].nY, "■");
	}

	ScreenFlipping();
}



void Release() {

}



int main(void) {
	int nKey;
	ScreenInit();
	init(); // 초기화

	while (1) {
		if (_kbhit()) {
			nKey = _getch();
			if (nKey == 224) {
				nKey = _getch();
				switch (nKey) {
				case 75:
					Snake.nDirect = LEFT;
					break;
				case 77:
					Snake.nDirect = RIGHT;
					break;
				case 72:
					Snake.nDirect = UP;
					break;
				case 80:
					Snake.nDirect = DOWN;
					break;
				}
			}
		}












		Update();  // 데이터 갱신
		Render();  // 화면출력		
	}
	Release(); // 해제
	ScreenRelease();
	return 0;
}