#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include"Screen.h""



void init() {

}
void Update() {
	
}

void Render() {

	ScreenClear();
	//����ڵ�
	ScreenFlipping();
}

void Release() {

}

int main(void) {
	
	ScreenInit();
	init(); // �ʱ�ȭ

	while (1) {

		Update();  // ������ ����
		Render();  // ȭ�����

		
	}
	Release(); // ����
	ScreenRelease();
	return 0;
}