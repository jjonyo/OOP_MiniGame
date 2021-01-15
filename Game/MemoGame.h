#pragma once
#include "Game.h"


#define FIRST_LINE_SIZE 12 //키보드 첫번째 줄 크기
#define SECOND_LINE_SIZE 11 //키보드 두번째 줄 크기
#define THIRD_LINE_SIZE 10 //키보드 세번째 줄 크기
#define KEY_SIZE FIRST_LINE_SIZE+SECOND_LINE_SIZE+THIRD_LINE_SIZE //전체 KEY 크기

#define START_SIZE 4

class MemoGame : public Game
{
	const int TIME_LIMIT = 30;

	class Key
	{

	private:
		char ch;
		int x, y;

	public:
		Key() : ch(0), x(0), y(0) {}
		void Setchar(char ch) { this->ch = ch; }
		char GetChar() { return ch; }
		void SetXy(int x, int y) { this->x = x, this->y = y; }
		void PrintKey();
	};

private:
	vector <Key> list; //하이라이트 될 KEY가 저장된 벡터
	vector <Key> ans; //사용자가 입력한 KEY가 저장된 벡터
	Key key[KEY_SIZE]; //전체 출력될 KEY
	int cur; //현재 사용자의 입력커서 위치

public:
	MemoGame() :cur(0) {}
	void Play();
	void Display_Rule(int x, int y);
	void SetList(int); //하이라이트 될 KEY 랜덤 설정
	void DisplayList(); //KEY 하이라이트
	void ansreset(); //사용자 입력 초기화

	void PrintBackground();
	void Printedge();
	void PrintAllKey();
	
	int Scoring(char key); //점수계산
};