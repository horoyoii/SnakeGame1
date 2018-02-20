// �� �����̴�!!

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
	int nX, nY;			// ��ǥ
	int nOldX, nOldY;	// ������ǥ
}POS;

// �� ����ü ����
typedef struct _SNAKE {	// �Ӽ���
	int nLife;					//���� 
	DIRECT nDirect;		// ������ ����
	clock_t MoveTime;		// �̵��ð�
	clock_t OldTime;		// ���� �̵��ð�
	POS sHead;				// �Ӹ��� ��ġ
	POS sTail[20];			// ������ ��ġ + �ִ� 20��
}SNAKE;

SNAKE Snake;

void Move() {
	// step1 : ���� ��ǥ�� ���� ��ǥ�� ����
	Snake.sHead.nOldX = Snake.sHead.nX;
	Snake.sHead.nOldY = Snake.sHead.nY;

	for (int i = 0; i < TAIL; i++) {
		Snake.sTail[i].nOldX = Snake.sTail[i].nX;
		Snake.sTail[i].nOldY = Snake.sTail[i].nY;
	}

	// step2 : ����� ������ǥ�� ���� ������ ������ǥ�� ����
	// 2-1. �Ӹ��� ������ǥ�� ù��° ������ ������ǥ�� ����
	Snake.sTail[0].nX = Snake.sHead.nOldX;
	Snake.sTail[0].nY = Snake.sHead.nOldY;
	// 2-2. ���� �����鿡 ���������� ��ǥ�� ����
	for (int i = 1; i < TAIL; i++) {
		Snake.sTail[i].nX = Snake.sTail[i - 1].nOldX;
		Snake.sTail[i].nY = Snake.sTail[i - 1].nOldY;
	}


}





void init() {

	// Snake �Ӹ� �ʱ�ȭ
	Snake.nLife = 1;
	Snake.sHead.nX = 30;
	Snake.sHead.nY = 10;
	Snake.sHead.nOldX = Snake.sHead.nX;
	Snake.sHead.nOldY = Snake.sHead.nY;
	Snake.MoveTime = 100;
	Snake.OldTime = clock();
	Snake.nDirect = LEFT;

	// Snake ���� �ʱ�ȭ
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
			if (Snake.sHead.nX - 2 > 1) { // ��迡�� ���� ���Ѵ�.
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
			if (Snake.sHead.nY - 1 > 1) { // �Ӹ��� y��ǥ�� 1�� ���� �� ��迡 �ش��ϴ� y��ǥ�� 1���� �۰ų� �������� ����ƴ���.
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
	//����ڵ�
	ScreenPrint(Snake.sHead.nX, Snake.sHead.nY, "��");
	for (int i = 0; i < TAIL; i++) {
		ScreenPrint(Snake.sTail[i].nX, Snake.sTail[i].nY, "��");
	}

	ScreenFlipping();
}



void Release() {

}



int main(void) {
	int nKey;
	ScreenInit();
	init(); // �ʱ�ȭ

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












		Update();  // ������ ����
		Render();  // ȭ�����		
	}
	Release(); // ����
	ScreenRelease();
	return 0;
}