#include "MemoGame.h"

#define fflush FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

void MemoGame::Play()
{
	system("mode con: cols=130 lines=30");
	this->score = 0;
	this->combo = 0;
	fflush;
	rewind(stdin);
	CursorView(0);

	Display_Rule(35, 3);
	Display_Start_count(55, 8);
	system("cls");

	_mutex.lock();
	PrintBackground();
	_mutex.unlock();

	thread time([&]() {Display_Countdown(13, 2, TIME_LIMIT); });
	int check = 0;
	char key;
	int num = 4;
	fflush;
	do
	{
		if (!check)
		{
			cur = 0;
			_mutex.lock();
			Display_Score(40, 2);
			Display_Combo(70, 2);
			_mutex.unlock();
			SetList(num + (combo / 3));
			ansreset();
			DisplayList();
			fflush;
			check = 1;
		}
		if (_kbhit())
		{

			key = _getch();
			check = Scoring(key);
			_mutex.lock();
			Display_Score(40, 2);
			Display_Combo(70, 2);
			_mutex.unlock();
		}
		if (cur == num)
		{
			cur = 0;
			check = 0;
			combo++;
			_mutex.lock();
			SKY;
			Printedge();
			Orgn;
			_mutex.unlock();
			Sleep(80);
			_mutex.lock();
			Printedge();
			_mutex.unlock();
		}
	} while (!gameover_check);

	time.join();
	Display_Timeover(30, 5);

	CursorView(1);
}

void MemoGame::Display_Rule(int x, int y)
{
	int i;
	char msg[] = "Press Any Key to Continue . . .     ";
	int offset;
	system("cls");


	gotoxy(x, y); printf("━━━━━━━━━━━━ Memo Game Rule ━━━━━━━━━━━━");
	gotoxy(x, y + 3); printf("※키보드가 빨간색으로 변하는 순서를 기억하세요");
	gotoxy(x, y + 5); printf("※기억한 순서대로 키보드를 누르면 키보드에 파란불이 들어옵니다");
	gotoxy(x, y + 7); printf("※제한시간 안에 최대한 높은 점수를 획득하세요!");
	gotoxy(x, y + 8); printf("(콤보가 높아질수록 추가점수를 획득합니다.)");

	Key a, b, c;
	a.SetXy(x, y + 12);
	b.SetXy(x + 20, y + 12);
	c.SetXy(x + 40, y + 12);
	a.Setchar('A');
	b.Setchar('A');
	c.Setchar('A');

	a.PrintKey();
	RED;
	b.PrintKey();
	SKY;
	c.PrintKey();
	Orgn;

	while (!_kbhit())
	{
		for (offset = 0; offset < strlen(msg); offset++)
		{
			gotoxy(x + 3, y + 20);
			printf("%s", msg + offset);
			for (i = 0; i < offset; i++)
				printf("%c", msg[i]);
			Sleep(100);
			if (_kbhit())
				break;
		}
	}
}

void MemoGame::SetList(int size)
{
	srand((unsigned int)time(NULL));
	list.clear();
	int check[KEY_SIZE] = { 0 };
	for (int i = 0; i < size; i++)
	{
		int index;
		do
		{
			int random = rand();
			index = random % 33;
		} while (check[index]);

		check[index] = 1;
		list.push_back(key[index]);
	}
}

void MemoGame::DisplayList()
{
	int size = list.size();
	for (int i = 0; i < size; i++)
	{
		if (gameover_check) break;
		_mutex.lock();
		RED;
		sound("highlight");
		list[i].PrintKey();
		Orgn;
		_mutex.unlock();
		Sleep(1000);
		_mutex.lock();
		list[i].PrintKey();
		_mutex.unlock();
	}
}

void MemoGame::ansreset()
{
	int size = ans.size();
	for (int i = 0; i < size; i++)
	{
		_mutex.lock();
		ans[i].PrintKey();
		_mutex.unlock();
	}
	ans.clear();
}

void MemoGame::PrintAllKey()
{
	char first[13] = { 'Q','W','E','R','T','Y','U','I','O','P','[',']' };
	char second[12] = { 'A','S','D','F','G','H','J','K','L',';','\'' };
	char third[11] = { 'Z','X','C','V','B','N','M',',','.','/' };
	int x = 5, y = 6;
	for (int i = 0; i < FIRST_LINE_SIZE; i++)
	{
		key[i].Setchar(first[i]);
		key[i].SetXy(x, y);
		key[i].PrintKey();
		x += 10;
	}

	x = 7, y = 11;
	for (int i = 12; i < 12 + SECOND_LINE_SIZE; i++)
	{
		key[i].Setchar(second[i - 12]);
		key[i].SetXy(x, y);
		key[i].PrintKey();
		x += 10;
	}

	x = 10, y = 16;
	for (int i = 23; i < 23 + THIRD_LINE_SIZE; i++)
	{
		key[i].Setchar(third[i - 23]);
		key[i].SetXy(x, y);
		key[i].PrintKey();
		x += 10;
	}

}

void MemoGame::PrintBackground()
{
	PrintTime(3, 1);
	PrintScore(30, 1);
	PrintCombo(60, 1);
	Printedge();
	PrintAllKey();
	Display_Score(40, 2);
	Display_Combo(70, 2);
}

void MemoGame::Printedge()
{
	gotoxy(0, 5);
	printf("┏");
	for (int i = 1; i < 128; i++)
		printf("━");
	printf("┓");
	for (int y = 6; y < 22; y++)
	{
		gotoxy(0, y);
		printf("┃");
		gotoxy(128, y);
		printf("┃");
	}
	gotoxy(0, 22);
	printf("┗");
	for (int i = 1; i < 128; i++)
		printf("━");
	printf("┛");
}

int MemoGame::Scoring(char key)
{
	int ret = 0;
	key = toupper(key);
	gotoxy(3, 25);
	//printf("%c", key);
	if (list[cur].GetChar() == key)
	{
		sound("correct");
		score += 5000 + (combo * 200);
		SKY;
		_mutex.lock();
		list[cur].PrintKey();
		Orgn;
		_mutex.unlock();
		ans.push_back(list[cur]);
		ret = 1;
		cur++;
	}
	else
	{
		sound("wrong");
		_mutex.lock();
		RED;
		Printedge();
		Orgn;
		_mutex.unlock();
		Sleep(80);
		_mutex.lock();
		Printedge();
		_mutex.unlock();

		combo = 0;
	}

	return ret;
}

void MemoGame::Key::PrintKey()
{
	gotoxy(x, y);
	printf("┏━━━━━━┓");
	gotoxy(x, y + 1);
	printf("┃      ┃");
	gotoxy(x, y + 2);
	printf("┃      ┃");
	gotoxy(x, y + 3);
	printf("┃  %c   ┃", this->ch);
	gotoxy(x, y + 4);
	printf("┗━━━━━━┛");
}