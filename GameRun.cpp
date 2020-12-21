#include "GameRun.h"

std::ifstream infoRead;
std::ofstream infoWrite;

std::vector<UserInfo> userlist;

GameRun::GameRun() {}
GameRun::GameRun(std::vector<UserInfo>::iterator copy) { nowUser = copy; }

void GameRun::Start(int menu) { // game ���� �� ��� game start �Լ��� ����ǰ� ����
	std::string oneline; 
	char stringToChar[200];
	std::vector<UserInfo>::iterator p;

	infoRead.open("info.txt",std::ios_base::in);
	if (!(infoRead.is_open())) {
		std::ofstream makeFile("info.txt");
		makeFile.close();
		infoRead.open("info.txt", std::ios_base::in);
	}
	while (getline(infoRead, oneline)) {
		strcpy_s(stringToChar, oneline.c_str());
		userlist.push_back(UserInfo(stringToChar));
	}

	if (menu == 2) { // create id
		while (true) {
			std::string newInfoID, newInfoPW="";
			std::cout << "ID �Է� : ";
			std::cin >> newInfoID;
			std::cout << "PW �Է� : ";
			int i;
			char ch = 'a';
			for (i = 0; ch != 13; i++) //EnterŰ�� �Է¹��� ������ ���ڿ��� �Է¹���(13:Enter)
			{
				ch = _getch();
				if (ch != 13) newInfoPW.append(std::to_string(ch));
				std::cout << '*'; //��ȣ�� *�� ǥ��
			}
			std::cout << "\n";
			p = find(userlist.begin(), userlist.end(), newInfoID);
			if (p == userlist.end()) {
				userlist.push_back(UserInfo(newInfoID,newInfoPW));
				break;
			}
			else {
				std::cout << "�ߺ��� ID �Դϴ�." << std::endl;
			}

		}
	}
	if (Login()) { // login ���� �ϸ� mainMenu��
		this->mainMenu();
	}
	else return; // login �����ϸ� ����
	infoWrite.open("info.txt", std::ios::out); // mainMenu���� exit�� �� userlist�� info.txt�� ����
	p = userlist.begin();
	while (p!=userlist.end()) {
		oneline.assign(p->getID());
		oneline.append(" ");
		oneline.append(p->getPW());
		oneline.append(" ");
		oneline.append(to_string(p->getScore(1)));
		oneline.append(" ");
		oneline.append(to_string(p->getScore(2)));
		oneline.append(" ");
		oneline.append(to_string(p->getScore(3)));
		infoWrite << oneline << std::endl;
		p++;
	}
	infoRead.close();
	infoWrite.close();
}
std::vector<UserInfo>::iterator GameRun::findUser(std::string ID) { // userlist���� �ش� id�� user�� UserInfo�� ��ġ
	std::vector<UserInfo>::iterator posID;
	posID = find(userlist.begin(), userlist.end(), ID);
	return posID;
}

bool GameRun::Login() { 
	std::vector<UserInfo>::iterator posID;
	std::string inputID;
	while (true) {
		system("cls");
		std::cout << "ID : "; // id �Է�
		std::cin >> inputID;
		posID = findUser(inputID);
		if (posID == userlist.end()) { 
			std::string yn;
			std::cout << "\n�������� �ʴ� ID�Դϴ�.\n������ �����Ͻðڽ��ϱ� (y/n) ";
			std::cin >> yn;
			if (yn.compare("y")==0) return false;
			else continue;
		}
		if (posID->checkIDPW()) { // pw �Է� �� Ȯ�� �� nowUser=posID
			this->nowUser = posID;
			return true;
		}
	}
}
void GameRun::mainMenu() {
	int menu=0;
	while (menu != 5) {
		system("cls");
		std::cout << "welcome \""
			<< this->nowUser->getID() << "\"" << std::endl;
		std::cout << "1. Play Game\n"
			<< "2. Practice Game\n"
			<< "3. Show Rank\n"
			<< "4. My Page\n"
			<< "5. Exit\n"
			<< ">> "; 

		std::cin >> menu;
		if (!cin) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			menu = 0;
			continue;
		}
		switch (menu) {
		case 1: // game�� �����ϰ� ����
			this->RealGame();
			break;
		case 2: // game�� �����ϴ� ��������
			this->PracticeGame();
			break;
		case 3: // ���Ӻ� ��ŷ
			this->showRank();
			break;
		case 4: // id, ���� Ȯ��
			this->myPage();
			break;
		case 5:
			return;
		}
	}
}
void GameRun::RealGame()/* ���� ���� */
{
	Game* gm = NULL;
	vector<int> num{1,2,3};
	vector<int>::iterator random;
	int order[3];
	int i;
	srand((unsigned int)time(0));

	random = find(num.begin(), num.end(), rand() % 3 + 1);
	order[0] = *random;
	num.erase(random);
	if (rand() % 2 == 0) {
		order[1] = num.front();
		order[2] = num.back();
	}
	else {
		order[1] = num.back();
		order[2] = num.front();
	}
	std::cout << "Random Game Start!" << std::endl;
	Sleep(2000);
	
	for (i = 0; i < 3; i++) {
		switch (order[i])
		{
		case 1:
			gm = new ArrowGame;
			break;
		case 2:
			gm = new MemoGame;
			break;
		case 3:
			gm = new RainGame;
			break;
		}
		gm->Play();
		this->nowUser->updateScore(gm->Get_Score(), order[i]);
		delete gm;
	}
}
void GameRun::PracticeGame() { /* �������� */
	Game* gm = NULL;
	int sel;
	 // �������� ����
	std::cout << "1. Arrow Game\n"
		<< "2. Memo Game\n"
		<< "3. Rain Game\n"
		<< ">> ";
	std::cin >> sel;
	if (!cin) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		}

	switch (sel) {
	case 1:
		gm = new ArrowGame;
		break;
	case 2:
		gm = new MemoGame;
		break;
	case 3:
		gm = new RainGame;
		break;
	}
	gm->Play();
	std::cout << " ** Score : " << gm->Get_Score() << " **" << std::endl;
	Sleep(2000);
	delete gm;
}
void GameRun::showRank() {
	int gnum=0;
	std::string nowID="";
	std::vector<UserInfo>::iterator p;
	nowID.assign((this->nowUser->getID()).c_str()); // userlist�� ��ġ�� �ٲ�Ƿ� ���� ID�� ����
	while (gnum!=4) {
		std::cout << "1. Arrow Game Rank\n"
			<< "2. Memo Game Rank\n"
			<< "3. Rain Game Rank\n"
			<< "4. Main Menu\n"
			<< ">> ";
		std::cin >> gnum;
		if (!cin) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			gnum = 0;
			continue;
		}
		system("cls");
		switch (gnum) {
		case 1:
			sort(userlist.begin(), userlist.end(), UserInfo::comp_arrow);
			break;
		case 2:
			sort(userlist.begin(), userlist.end(), UserInfo::comp_memo);
			break;
		case 3:
			sort(userlist.begin(), userlist.end(), UserInfo::comp_rain);
			break;
		case 4:
			this->nowUser = (this->findUser(nowID));
			return;
		default:
			std::cout << "�߸� �Է��ϼ̽��ϴ�." << std::endl;
			continue; // �ٽ� �Է�
		}
		std::cout << "ID : score\n";
		p = userlist.begin(); 
		while (p != userlist.end()) { // ���
			std::cout << p->getID() << " : " << p->getScore(gnum) << "\n";
			p++;
		}
	}
	this->nowUser = (this->findUser(nowID)); // ���� ���ĵ� userlist���� nowID�� ���� user�� ��ġ�� ã��
}
void GameRun::myPage() {
	std::cout << "ID : " << this->nowUser->getID() << "\n"
		<< "Arrow Game score : " << this->nowUser->getScore(1) << "\n"
		<< "Memo Game score : " << this->nowUser->getScore(2) << "\n"
		<< "Rain Game score : " << this->nowUser->getScore(3) << "\n"
		<< "Press a key\n";
	getchar();
	if (_getch()) return; // �ƹ� Ű�� ������ �Լ� ����
}