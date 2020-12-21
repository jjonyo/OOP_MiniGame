#include "ArrowGame.h"

#define fflush FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

void ArrowGame::Play()
{
	system("mode con: cols=130 lines=30");
	fflush;
	this->score = 0;
	this->combo = 0;

	//커서숨김
	CursorView(0);

	Display_Rule(35, 3);
	Display_Start_count(55, 8);
	system("cls");

	thread time([&]() {Display_Countdown(13, 2, TIME_LIMIT); });
	int check = 0;
	char key;
	this->cur = 0;
	fflush;
	rewind(stdin);
	do
	{
		if (!check)
		{
			_mutex.lock();
			PrintBackground();
			ClearBoard();
			SetArrowList();
			PrintArrowList();
			Display_Score(40, 2);
			Display_Combo(70, 2);
			_mutex.unlock();
			check = 1;
		}

		if (_kbhit())
		{
			key = _getch();
			if (key == -32)
				key = _getch();
			Scoring(key);
			_mutex.lock();
			Display_Score(40, 2);
			Display_Combo(70, 2);
			_mutex.unlock();
		}

		if (cur == ARROW_SIZE)
		{
			cur = 0;
			check = 0;
		}
	} while (!gameover_check);

	time.join();
	Display_Timeover(30, 5);
	CursorView(1);
}

void ArrowGame::Display_Rule(int x, int y)
{
	int i;
	char msg[] = "Press Any Key to Continue . . .     ";
	int offset;
	system("cls");

	Arrow ex, ex2;
	ex.Setxy(x + 3, y + 11);
	ex.SetDir(LEFT);
	ex.PrintArrow();

	ex2.Setxy(x + 25, y + 11);
	ex2.SetDir(LEFT);
	SKY;
	ex2.PrintArrow();
	Orgn;


	gotoxy(x, y); printf("━━━━━━━━━━━━ Arrow Game Rule ━━━━━━━━━━━━");
	gotoxy(x, y + 3); printf("※화살표 모양을 순서대로 입력하세요.");
	gotoxy(x, y + 5); printf("※입력이 맞을경우 화살표에 파란불이 들어옵니다.");
	gotoxy(x, y + 7); printf("※제한시간 안에 최대한 높은 점수를 획득하세요!");
	gotoxy(x, y + 8); printf("(콤보가 높아질수록 추가점수를 획득합니다.)");

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

void ArrowGame::PrintBackground()
{
	PrintTime(3, 1);
	PrintScore(30, 1);
	PrintCombo(60, 1);
	Printedge();

}

void ArrowGame::Printedge()
{
	gotoxy(0, 8);
	printf("┏");
	for (int i = 1; i < 128; i++)
		printf("━");
	printf("┓");
	for (int y = 9; y < 24; y++)
	{
		gotoxy(0, y);
		printf("┃");
		gotoxy(128, y);
		printf("┃");
	}
	gotoxy(0, 24);
	printf("┗");
	for (int i = 1; i < 128; i++)
		printf("━");
	printf("┛");
}

void ArrowGame::SetArrowList()
{
	srand((unsigned)time(0));
	list.clear();
	int x = 2, y = 13;
	for (int i = 0; i < ARROW_SIZE; i++)
	{
		int dir = rand() % 4 + 1;
		Arrow ar;
		if (dir == 1) dir = UP;
		else if (dir == 2) dir = DOWN;
		else if (dir == 3) dir = LEFT;
		else if (dir == 4) dir = RIGHT;

		ar.SetDir(dir);
		ar.Setxy(x, y);
		list.push_back(ar);
		x += 14;
	}
}

void ArrowGame::PrintArrowList()
{
	for (int i = 0; i < ARROW_SIZE; i++)
	{
		list[i].PrintArrow();
	}
}

void ArrowGame::Scoring(int key)
{
	if (list[cur].isCorrect(key)) //정답
	{
		sound("correct");
		SKY;
		_mutex.lock();
		list[cur].PrintArrow();
		_mutex.unlock();
		Orgn;
		cur++;
		score += 1000 + (combo * 100);
		combo++;
	}
	else //오답
	{
		sound("wrong");
		combo = 0;
	}
}

void ArrowGame::ClearBoard()
{
	for (int i = 9; i <= 23; i++)
	{
		gotoxy(2, i);
		for (int j = 1; j < 127; j++)
			printf(" ");
	}
}

int ArrowGame::Arrow::isCorrect(int key)
{
	if (this->dir == key) return 1;
	else return 0;
}

void ArrowGame::Arrow::PrintArrow()
{
	switch (dir)
	{
	case UP:
	{
		gotoxy(x + 4, y);
		printf("■\n");
		gotoxy(x + 2, y + 1);
		printf("■■■\n");
		gotoxy(x, y + 2);
		printf("■■■■■\n");
		gotoxy(x + 2, y + 3);
		printf("■■■\n");
		gotoxy(x + 2, y + 4);
		printf("■■■\n");
		gotoxy(x + 2, y + 5);
		printf("■■■\n");
		break;
	}
	case DOWN:
	{
		gotoxy(x + 2, y);
		printf("■■■\n");
		gotoxy(x + 2, y + 1);
		printf("■■■\n");
		gotoxy(x + 2, y + 2);
		printf("■■■\n");
		gotoxy(x, y + 3);
		printf("■■■■■\n");
		gotoxy(x + 2, y + 4);
		printf("■■■\n");
		gotoxy(x + 4, y + 5);
		printf("■\n");
		break;
	}
	case LEFT:
	{
		gotoxy(x + 4, y + 1);
		printf("■");
		gotoxy(x + 2, y + 2);
		printf("■■■■■");
		gotoxy(x, y + 3);
		printf("■■■■■■");
		gotoxy(x + 2, y + 4);
		printf("■■■■■");
		gotoxy(x + 4, y + 5);
		printf("■");
		break;
	}
	case RIGHT:
	{
		gotoxy(x + 6, y + 1);
		printf("■");
		gotoxy(x, y + 2);
		printf("■■■■■");
		gotoxy(x, y + 3);
		printf("■■■■■■");
		gotoxy(x, y + 4);
		printf("■■■■■");
		gotoxy(x + 6, y + 5);
		printf("■");
		break;
	}
	}

}