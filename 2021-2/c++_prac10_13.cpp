#include<iostream>
#include<string>
#include<map>

 // map컨테이너를 이용하여 (이름, 성적)을 저장하고 이름으로 성적을 조회하는 점수 관리 프로그램을 만들어라. 이름은 빈칸 없이 입력하는 것을 원칙으로 한다.
//명품c++ 10장 실습문제 13번

using namespace std;

class GradeManager {
	map<string, int>inform;
	string program_name;
	string name;
	int score;
public:
	GradeManager(string name="") { program_name = name; }
	bool checkError();
	void run();
	void insert();
	void search();

};
bool GradeManager::checkError() {
	if (cin.fail()) {
		cin.clear(); //입력된 것 제거
		cin.ignore(100, '\n');//개행문자 제거
		cout << "입력 오류" << endl;
		return true;
	}
	return false;
}
void GradeManager::run() {
	int choose;
	cout << "***** 점수 관리 프로그램 " << program_name << "을 시작합니다. *****" << endl;
	do {
		cout << "입력: 1, 조회: 2, 종료: 3 >> ";
		cin >> choose;

		if (checkError()) {continue;}

		switch (choose)
		{
		case 1:
			insert();
			break;
		case 2:
			search();
			break;
		case 3:
			cout << "프로그램을 종료합니다..."; return;
		}
	} while (true);
}
void GradeManager::insert() {
	do {
		cout << "이름과 점수 >> ";
		cin >> name >> score;
		if (checkError())continue;

		if (inform.find(name) != inform.end()) {
			cout << "이미 입력된 이름입니다." << endl; break;
		}
		else {
			inform[name] = score;
			break;
		}
	} while (true);
}
void GradeManager::search() {
	cout << "이름 >> ";
	cin >> name;
	if (inform.find(name) == inform.end()) {
		cout << "등록되지 않은 이름입니다" << endl;
	}
	else {
		cout << name << "의 점수는 " << inform[name] << endl;
	}
}
int main() {
	GradeManager gm("HIGH SCORE");
	gm.run();
}
