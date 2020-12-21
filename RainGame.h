#pragma once
#include "Game.h"

#define OBJECT_SIZE 4 //OBJECT(물방울, 번개) 크기

class RainGame : public Game
{
	enum { rain = 1, light = 2 };
	enum { center = 1 };
	const int TIME_LIMIT = 20;

	class Object
	{

	private:
		int attribute;
		int dir;
		int x;
		int y;

	public:
		Object() : attribute(0), dir(0), x(0), y(0) {}
		void Printobject();

		void SetAtt(int at) { this->attribute = at; }
		void SetDir(int dir) { this->dir = dir; }
		void Setxy(int x, int y) { this->x = x, this->y = y; }

		int GetAtt() { return attribute; }
		int GetDir() { return dir; }
		int GetX() { return x; }
		int GetY() { return y; }
	};

	class Umbrella
	{
	private:
		int dir;

	public:
		Umbrella() : dir(0) {}
		void PrintUmb(int, int);
		void SetDir(int dir) { this->dir = dir; }
		int GetDir() { return dir; }
	};

private:
	deque <Object> list;

public:
	RainGame() {}
	void Play();
	void Display_Rule(int x, int y);
	void SetObjectList(); //OBJECT 랜덤 생성
	void PrintObjectList(); //list에 있는 OBJECT 출력
	void ProcessList(); //front의 OBJECT POP & 새로운 OBJECT PUSH

	void PrintBackground();
	void Printedge();
	void UmbPrint(Umbrella&, int);
	void ClearBoard();
	void ClearUmb();

	int Scoring(int key); //점수계산
	
};