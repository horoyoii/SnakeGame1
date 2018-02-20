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
	//출력코드
	ScreenFlipping();
}

void Release() {

}

int main(void) {
	
	ScreenInit();
	init(); // 초기화

	while (1) {

		Update();  // 데이터 갱신
		Render();  // 화면출력

		
	}
	Release(); // 해제
	ScreenRelease();
	return 0;
}