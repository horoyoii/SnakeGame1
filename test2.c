#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int main(void) {
	// _getch()
	// int _getch(void); - 문자를 아스키코드로 받기에 int형 return
	// scanf()와 달리 출력되지 않는다.
	/*
	// _kbhit
	// int _kbhit(void)
	// 키보드의 눌림이 감지되면 0이외의 값을 return 한다.
	int nChar;
	while (1) {
		if (_kbhit()) {
			nChar = _getch();
			if (nChar == 'q')
				break;
			
		}
		printf("%c", 'a');
		
	}
	printf("종료");
	*/
	/*
	char c;
	while (1) {
		if (_kbhit()) {
			c = _getch();
			if (c == -32) {
				c = _getch();
				switch (c) {
				case LEFT:
					printf("좌로 이동\n");
					break;
				case RIGHT:
					printf("우로 이동\n");
					break;
				case UP:
					printf("위로 이동\n");
					break;
				case DOWN:
					printf("아래로 이동\n");
					break;
				}
			}
		}
	}
	*/

	
	return 0;
}
