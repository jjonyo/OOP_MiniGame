#pragma once
#include "UserInfo.h"
#include "RainGame.h"
#include "ArrowGame.h"
#include "MemoGame.h"

#include <fstream>
#include <vector>
//#include <string>
//#include <iostream>
//#include <algorithm>
//#include <ctime>

class GameRun {
private:
	std::vector<UserInfo>::iterator nowUser; // 현재 게임을 하고 있는 nowUser의 userlist에서의 위치
public:
	GameRun();
	GameRun(std::vector<UserInfo>::iterator copy);

	std::vector<UserInfo>::iterator findUser(std::string ID);
	void Start(int menu);
	bool Login();
	void mainMenu();
	void RealGame();
	void PracticeGame();
	void showRank();
	void myPage();
};
