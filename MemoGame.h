#pragma once
#include "Game.h"


#define FIRST_LINE_SIZE 12 //Ű���� ù��° �� ũ��
#define SECOND_LINE_SIZE 11 //Ű���� �ι�° �� ũ��
#define THIRD_LINE_SIZE 10 //Ű���� ����° �� ũ��
#define KEY_SIZE FIRST_LINE_SIZE+SECOND_LINE_SIZE+THIRD_LINE_SIZE //��ü KEY ũ��

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
	vector <Key> list; //���̶���Ʈ �� KEY�� ����� ����
	vector <Key> ans; //����ڰ� �Է��� KEY�� ����� ����
	Key key[KEY_SIZE]; //��ü ��µ� KEY
	int cur; //���� ������� �Է�Ŀ�� ��ġ

public:
	MemoGame() :cur(0) {}
	void Play();
	void Display_Rule(int x, int y);
	void SetList(int); //���̶���Ʈ �� KEY ���� ����
	void DisplayList(); //KEY ���̶���Ʈ
	void ansreset(); //����� �Է� �ʱ�ȭ

	void PrintBackground();
	void Printedge();
	void PrintAllKey();
	
	int Scoring(char key); //�������
};