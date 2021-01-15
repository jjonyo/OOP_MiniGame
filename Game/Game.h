#pragma once
#include <iostream>
#include <thread>
#include <time.h>
#include <windows.h>
#include <mutex>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <deque>

using namespace std;

void gotoxy(int x, int y); //Ŀ�� ��ǥ �̵�
void CursorView(char show); //Ŀ�� �����

/*---------�ܼ� ������� ����---------*/
#define COL GetStdHandle(STD_OUTPUT_HANDLE) 
#define SKY SetConsoleTextAttribute(COL, 0x000b);
#define Orgn SetConsoleTextAttribute(COL, 0x0007)
#define RED SetConsoleTextAttribute(COL,0x000c );
#define YELLOW SetConsoleTextAttribute(COL,0x000e );

/*---------ȿ���� ����---------*/
#pragma comment(lib,"winmm.lib") 
#define sound(a) PlaySound(TEXT(a), NULL, SND_FILENAME | SND_ASYNC)

enum { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 }; //Ű���� �Է� ó��

class Game
{
protected:
	int score; //���� ����
	int combo; //���� �޺�
	bool gameover_check; //Time over üũ�� ���� ����
	mutex _mutex; //������ ����ȭ�� ���

public:
	Game() : score(0), gameover_check(0), combo(0) { }
	virtual void Play() {}

	int Get_Score() { return score; }

	/*---------����UI ����Լ�---------*/
	void Display_Countdown(int x, int y, int Time);
	void Display_Score(int x, int y);
	void Display_Combo(int x, int y);
	void Display_Timeover(int, int);
	void Display_Start_count(int x, int y);
	void PrintTime(int, int);
	void PrintScore(int, int);
	void PrintCombo(int, int);
	void PrintTimeover(int, int);
};

