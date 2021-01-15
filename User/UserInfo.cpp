# include "UserInfo.h"

UserInfo::UserInfo(std::string newID,std::string newPW) { 
	this->userID = newID; 
	this->userPW = newPW;
	this->scoreArrow = 0; 
	this->scoreMemo = 0;
	this->scoreRain = 0;
}
UserInfo::UserInfo(char* originalData) { // txt 파일 한줄을 userinfo의 id, pw, score로 저장
	char* context = NULL;
	char* ptr = strtok_s(originalData, " ", &context);
	std::string strID(ptr);
	this->userID = strID;
	ptr = strtok_s(NULL, " ", &context);
	std::string strPW(ptr);
	this->userPW = strPW;
	ptr = strtok_s(NULL, " ", &context);
	this->scoreArrow = atoi(ptr);
	ptr = strtok_s(NULL, " ", &context);
	this->scoreMemo = atoi(ptr);
	ptr = strtok_s(NULL, " ", &context);
	this->scoreRain = atoi(ptr);
}
bool UserInfo::checkIDPW() // 입력한 pw가 this->userPW와 일치하는지
{
	std::string chPW;
	int i;
	char ch = 'a';
	system("cls");
	std::cout << "ID : "<<this->getID();
	std::cout << "\nPW : ";
	for (i = 0; ch != 13; i++) //Enter키를 입력받을 때까지 문자열을 입력받음(13:Enter)
	{
		ch =_getch();
		if(ch!=13)chPW.append(std::to_string(ch));
		std::cout << '*'; //암호를 *로 표시
	}
	if ((this->getPW().compare(chPW))==0) return true;
	else return false;
}
int UserInfo::getScore(int sel) { // sel 값에 따라 각 점수 return
	switch (sel)
	{
	case 1:
		return this->scoreArrow; 
	case 2:
		return this->scoreMemo;
	case 3:
		return this->scoreRain;
	}
}
void UserInfo::updateScore(int newScore, int gnum) { // 새 점수가 더 높으면 update
	switch (gnum)
	{
	case 1:
		if (newScore > this->getScore(1))
		{
			this->scoreArrow = newScore;
			scorePrint(newScore, true);
			return;
		}
		break;
	case 2:
		if (newScore > this->getScore(2)) {
			this->scoreMemo = newScore;
			scorePrint(newScore, true);
			return;
		}
		break;
	case 3:
		if (newScore > this->getScore(3)) {
			this->scoreRain = newScore;
			scorePrint(newScore, true);
			return;
		}
		break;
	default:
		break;
	}
	scorePrint(newScore, false); // update후, 점수 print
}
void UserInfo::scorePrint(int newScore, bool save) // save가 true이면 newScore가 기존 점수 보다 높음
{
	system("cls");
	std::cout << "** Score : " << newScore << " **\n";
	if (save) {
		std::cout << "Succeed to update score!" << std::endl;
	}
	else {
		std::cout << "Failed to update score!" << std::endl;
	}
	Sleep(2000);
}
// sort 함수에 쓸 비교 함수
bool UserInfo::comp_arrow(const UserInfo& a, const UserInfo& b)
{
	return (a.scoreArrow > b.scoreArrow);
}
bool UserInfo::comp_memo(const UserInfo& a, const UserInfo& b)
{
	return (a.scoreMemo > b.scoreMemo);
}
bool UserInfo::comp_rain(const UserInfo& a, const UserInfo& b)
{
	return (a.scoreRain > b.scoreRain);
}