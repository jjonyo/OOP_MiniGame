#pragma once
//#include <cstring>
#include <stdlib.h>
#include<iostream>
#include <algorithm>
#include <conio.h>
#include <string>
#include <windows.h>

class UserInfo 
{
private:
	std::string userID;
	std::string userPW;
	int scoreArrow;
	int scoreMemo;
	int scoreRain;

public:
	UserInfo(std::string newID, std::string newPW);
	UserInfo(char* originalData);

	std::string getID() { return userID; }
	std::string getPW() { return userPW; }
	bool checkIDPW();
	int getScore(int sel);
	void updateScore(int newScore,int gnum);
	void scorePrint(int newScore, bool save);

	bool operator==(const std::string a)
	{
		if (this->userID.compare(a) == 0) return true;
		else return false;
	}
	static bool comp_arrow(const UserInfo& a, const UserInfo& b);
	static bool comp_memo(const UserInfo& a, const UserInfo& b);
	static bool comp_rain(const UserInfo& a, const UserInfo& b);
};