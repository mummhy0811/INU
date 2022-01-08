#include <iostream>
#include <map>
#include<string>

//암호 관리 응용 프로그램을 map을 이용하여 작성하라.
//명품 c++10장 실습문제 14번
using namespace std;

class Sec {
	string app_name;
	map<string , string > manage;
public:
	Sec(string name) {
		this->app_name = name;
	}

	void run();
	void insert();
	void test();
};


void Sec::run() {
	int num;
	cout << "***암호 관리 프로그램 " << app_name << "을 시작합니다. ***" << endl;
	do {
		cout << "삽입:1, 검사:2, 종료:3>> ";
		cin >> num;

		switch (num) {
		case 1:
			insert(); break;
		case 2:
			test(); break;
		case 3:
			cout << "프로그램을 종료합니다... "; return;
		default:
			cout << "잘못된 입력입니다..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			break;
		}


	} while (true);
}

void Sec::insert() {
	string name, password;
	do {
		cout << "이름 암호>> ";
		cin >> name >> password;


		if (manage.find(name) == manage.end()) {
			manage[name] = password;
			break;
		}
		else {
			cout << "이미 등록된 이름입니다. " << endl;
		}
	} while (true);
	
}

void Sec::test() {
	string enter_name, enter_password;
	do {
		cout << "이름?";
		cin >> enter_name;
		if (manage.find(enter_name) == manage.end()) { //입력한 이름이 목록에 없는 경우
			cout << "없는 이름입니다" << endl; continue;
		}
		else {//이름이 목록에 있는 경우
			do {
				cout << "암호? ";
				cin >> enter_password;
				if (manage[enter_name] == enter_password) {
					cout << "통과!! "<<endl; return;
				}
				else {
					cout << "실패~~ "<<endl;
				}
			} while (manage[enter_name] != enter_password);
		}
	} while (true);
}
int main() {
	Sec s("WHO");
	s.run();
}
