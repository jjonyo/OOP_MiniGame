#include "RainGame.h"

#define fflush FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

void RainGame::Play()
{
	system("mode con: cols=90 lines=60");
	this->score = 0;
	this->combo = 0;
	fflush;
	rewind(stdin);
	CursorView(0);

	Display_Rule(22, 10);
	Display_Start_count(36, 20);
	system("cls");

	thread time([&]() {Display_Countdown(13, 2, TIME_LIMIT); });

	_mutex.lock();
	PrintBackground();
	Printedge();
	SetObjectList();
	PrintObjectList();

	Umbrella umb;
	UmbPrint(umb, center);
	_mutex.unlock();

	char key;
	int check = -1;
	fflush;
	do
	{
		if (check == 1)
		{
			_mutex.lock();
			ClearBoard();
			ProcessList();
			PrintObjectList();
			UmbPrint(umb, key);
			Display_Score(40, 2);
			_mutex.unlock();
			check = -1;
		}
		else if (check == 0)
		{
			_mutex.lock();
			int dir = umb.GetDir();
			ClearUmb();
			RED;
			UmbPrint(umb, dir);
			Orgn;
			_mutex.unlock();
			check = -1;
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == -32)
				key = _getch();
			check = Scoring(key);
			Display_Combo(70, 2);
		}
	} while (!gameover_check);
	time.join();
	Display_Timeover(15, 20);

	CursorView(1);
}

void RainGame::Display_Rule(int x, int y)
{
	int i;
	char msg[] = "Press Any Key to Continue . . .     ";
	int offset;
	system("cls");




	gotoxy(x, y); printf("━━━━━━━━━━━━ Rain Game Rule ━━━━━━━━━━━━");
	gotoxy(x, y + 3); printf("※키보드로 우산을 움직여 비를 막아야 합니다.");
	gotoxy(x, y + 5); printf("※만약 번개가 나타난다면 반대 키를 눌러 번개를 피하세요!");
	gotoxy(x, y + 7); printf("※제한시간 안에 최대한 높은 점수를 획득하세요!");
	gotoxy(x, y + 8); printf("(콤보가 높아질수록 추가점수를 획득합니다.)");

	Object a, b;
	a.SetAtt(rain);
	a.Setxy(x + 5, y + 15);
	a.Printobject();

	b.SetAtt(light);
	b.Setxy(x + 30, y + 16);
	b.Printobject();

	while (!_kbhit())
	{
		for (offset = 0; offset < strlen(msg); offset++)
		{
			gotoxy(x + 3, y + 25);
			printf("%s", msg + offset);
			for (i = 0; i < offset; i++)
				printf("%c", msg[i]);
			Sleep(100);
			if (_kbhit())
				break;
		}
	}

}

void RainGame::SetObjectList()
{
	srand((unsigned)time(0));
	int left_x = 26;
	int right_x = 57;
	int firsty = 40;
	for (int i = 0; i < OBJECT_SIZE; i++)
	{
		int dir = rand() % 2;
		int Att = rand() % 3 + 1;
		if (Att == 3) Att = 1;
		Object ob;
		if (dir == 0)
		{
			ob.SetAtt(Att);
			ob.Setxy(left_x, firsty);
			ob.SetDir(LEFT);

		}
		else if (dir == 1)
		{
			ob.SetAtt(Att);
			ob.Setxy(right_x, firsty);
			ob.SetDir(RIGHT);
		}
		list.push_back(ob);
		firsty -= 10;
	}
}

void RainGame::PrintObjectList()
{
	for (int i = 0; i < OBJECT_SIZE; i++)
	{
		list[i].Printobject();
	}
}

void RainGame::ProcessList()
{
	list.pop_front();
	int dir = rand() % 2;
	int Att = rand() % 3 + 1;
	if (Att == 3) Att = 1;
	Object ob;
	if (dir == 0) {
		ob.SetAtt(Att);
		ob.Setxy(26, 10);
		ob.SetDir(LEFT);
	}
	else if (dir == 1)
	{
		ob.SetAtt(Att);
		ob.Setxy(57, 10);
		ob.SetDir(RIGHT);
	}
	list.push_back(ob);

	for (int i = 0; i < OBJECT_SIZE - 1; i++)
	{
		int x = list[i].GetX();
		int y = list[i].GetY();

		list[i].Setxy(x, y + 10);
	}
}

void RainGame::ClearBoard()
{
	for (int y = 6; y < 57; y++)
	{
		for (int x = 15; x < 65; x++)
		{
			gotoxy(x, y);
			printf(" ");
		}
	}
}

void RainGame::ClearUmb()
{
	for (int y = 45; y < 57; y++)
	{
		for (int x = 15; x < 65; x++)
		{
			gotoxy(x, y);
			printf(" ");
		}
	}
}

void RainGame::PrintBackground()
{
	PrintTime(3, 1);
	PrintScore(30, 1);
	PrintCombo(60, 1);
}

void RainGame::Printedge()
{
	gotoxy(10, 5);
	printf("┏");
	for (int i = 0; i < 60; i++)
		printf("━");
	printf("┓");
	for (int y = 6; y < 58; y++)
	{
		gotoxy(10, y);
		printf("┃");
		gotoxy(71, y);
		printf("┃");
	}
	gotoxy(10, 58);
	printf("┗");
	for (int i = 0; i < 60; i++)
		printf("━");
	printf("┛");
}

int RainGame::Scoring(int key)
{
	auto cur = list.front();
	int Att = cur.GetAtt();
	int ret = 0;
	if (Att == rain)
	{
		if (cur.GetDir() == key) //정답
		{
			sound("correct");
			score += 1000 + (combo * 100);
			combo++;
			ret = 1;
		}
		else
		{
			sound("wrong");
			combo = 0;
			ret = 0;
		}
	}
	else if (Att == light)
	{
		if (cur.GetDir() != key) //정답
		{
			sound("correct");
			score += 1000 + (combo * 100);
			combo++;
			ret = 1;
		}
		else
		{
			sound("wrong");
			combo = 0;
			ret = 0;
		}
	}

	return ret;
}

void RainGame::UmbPrint(Umbrella& umb, int dir)
{
	umb.SetDir(dir);
	switch (dir)
	{
	case center:
		umb.PrintUmb(40, 50);
		break;
	case LEFT:
		umb.PrintUmb(25, 50);
		break;
	case RIGHT:
		umb.PrintUmb(55, 50);
	}
}

void RainGame::Umbrella::PrintUmb(int x, int y)
{
	gotoxy(x, y - 2);
	printf("●●●");
	gotoxy(x - 1, y - 1);
	printf("●●●●");
	gotoxy(x - 2, y);
	printf("●●●●●");
	gotoxy(x - 3, y + 1);
	printf("●●●●●●");
	gotoxy(x - 4, y + 2);
	printf("●●●●●●●");
	gotoxy(x + 2, y + 3);
	printf("●");
	gotoxy(x + 2, y + 4);
	printf("●");
	gotoxy(x - 1, y + 5);
	printf("● ●");
	gotoxy(x, y + 6);
	printf("●");
}

void RainGame::Object::Printobject()
{
	switch (this->attribute)
	{
	case rain:
	{
		SKY;
		gotoxy(x, y - 3);
		printf("●");
		gotoxy(x - 1, y - 2);
		printf("●●");
		gotoxy(x - 2, y - 1);
		printf("●●●");
		gotoxy(x - 3, y);
		printf("●●●●");
		gotoxy(x - 3, y + 1);
		printf("●●●●");
		gotoxy(x - 2, y + 2);
		printf("●●●");
		gotoxy(x - 1, y + 3);
		printf("●●");
		Orgn;
	}
	break;
	case light:
	{
		YELLOW;
		gotoxy(x, y - 4);
		printf("●");
		gotoxy(x - 1, y - 3);
		printf("●●");
		gotoxy(x - 2, y - 2);
		printf("●●");
		gotoxy(x - 3, y - 1);
		printf("●●●●");
		gotoxy(x - 4, y);
		printf("●●●●");
		gotoxy(x - 1, y + 1);
		printf("●●");
		gotoxy(x - 2, y + 2);
		printf("●●");
		gotoxy(x - 1, y + 3);
		printf("●");
		Orgn;
	}
	break;
	}
}