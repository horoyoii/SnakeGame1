#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80

int main(void) {
	// _getch()
	// int _getch(void); - ���ڸ� �ƽ�Ű�ڵ�� �ޱ⿡ int�� return
	// scanf()�� �޸� ��µ��� �ʴ´�.
	/*
	// _kbhit
	// int _kbhit(void)
	// Ű������ ������ �����Ǹ� 0�̿��� ���� return �Ѵ�.
	int nChar;
	while (1) {
		if (_kbhit()) {
			nChar = _getch();
			if (nChar == 'q')
				break;
			
		}
		printf("%c", 'a');
		
	}
	printf("����");
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
					printf("�·� �̵�\n");
					break;
				case RIGHT:
					printf("��� �̵�\n");
					break;
				case UP:
					printf("���� �̵�\n");
					break;
				case DOWN:
					printf("�Ʒ��� �̵�\n");
					break;
				}
			}
		}
	}
	*/

	
	return 0;
}
