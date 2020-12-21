#pragma once
#include "Game.h"

class ArrowGame : public Game
{
	#define ARROW_SIZE 9 //Arrow ����
	const int TIME_LIMIT = 20; //�ð����� ����

	class Arrow
	{
	private:
		int x;
		int y;
		int dir;

	public:
		Arrow() : dir(0) {}
		Arrow(int dir) { dir = dir; }
		void PrintArrow(); //ȭ��ǥ ���
		int isCorrect(int ans);
		void SetDir(int dir) { this->dir = dir; }
		int GetDir() { return dir; }
		void Setxy(int x, int y) { this->x = x, this->y = y; }
	};

private:
	vector <Arrow> list; //ȭ��ǥ�� ������� ���� ����
	int cur; //������� �Է�Ŀ�� ��ġ

public:
	ArrowGame() : cur(-1) {}
	void Play();
	void Display_Rule(int x, int y);

	void SetArrowList(); //ȭ��ǥ �������� & ���Ϳ� PUSH
	void PrintArrowList(); //list�� �ִ� ȭ��ǥ ���

	void PrintBackground();
	void Printedge();
	void ClearBoard();

	void Scoring(int key); //�������
};