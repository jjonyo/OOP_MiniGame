# include "UserInfo.h"

UserInfo::UserInfo(std::string newID,std::string newPW) { 
	this->userID = newID; 
	this->userPW = newPW;
	this->scoreArrow = 0; 
	this->scoreMemo = 0;
	this->scoreRain = 0;
}
UserInfo::UserInfo(char* originalData) { // txt ���� ������ userinfo�� id, pw, score�� ����
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
bool UserInfo::checkIDPW() // �Է��� pw�� this->userPW�� ��ġ�ϴ���
{
	std::string chPW;
	int i;
	char ch = 'a';
	system("cls");
	std::cout << "ID : "<<this->getID();
	std::cout << "\nPW : ";
	for (i = 0; ch != 13; i++) //EnterŰ�� �Է¹��� ������ ���ڿ��� �Է¹���(13:Enter)
	{
		ch =_getch();
		if(ch!=13)chPW.append(std::to_string(ch));
		std::cout << '*'; //��ȣ�� *�� ǥ��
	}
	if ((this->getPW().compare(chPW))==0) return true;
	else return false;
}
int UserInfo::getScore(int sel) { // sel ���� ���� �� ���� return
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
void UserInfo::updateScore(int newScore, int gnum) { // �� ������ �� ������ update
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
	scorePrint(newScore, false); // update��, ���� print
}
void UserInfo::scorePrint(int newScore, bool save) // save�� true�̸� newScore�� ���� ���� ���� ����
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
// sort �Լ��� �� �� �Լ�
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