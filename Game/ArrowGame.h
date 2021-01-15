#pragma once
#include "Game.h"

class ArrowGame : public Game
{
	#define ARROW_SIZE 9 //Arrow 개수
	const int TIME_LIMIT = 20; //시간제한 설정

	class Arrow
	{
	private:
		int x;
		int y;
		int dir;

	public:
		Arrow() : dir(0) {}
		Arrow(int dir) { dir = dir; }
		void PrintArrow(); //화살표 출력
		int isCorrect(int ans);
		void SetDir(int dir) { this->dir = dir; }
		int GetDir() { return dir; }
		void Setxy(int x, int y) { this->x = x, this->y = y; }
	};

private:
	vector <Arrow> list; //화살표를 순서대로 담을 벡터
	int cur; //사용자의 입력커서 위치

public:
	ArrowGame() : cur(-1) {}
	void Play();
	void Display_Rule(int x, int y);

	void SetArrowList(); //화살표 랜덤생성 & 벡터에 PUSH
	void PrintArrowList(); //list에 있는 화살표 출력

	void PrintBackground();
	void Printedge();
	void ClearBoard();

	void Scoring(int key); //점수계산
};