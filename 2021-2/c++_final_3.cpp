#include <iostream>
#include <string>
#include <map>
using namespace std;

class Animal {
protected:
	string name; // 동물의 이름
public:
	Animal(string name) {
		this->name = name;
	}
	virtual string getCry() = 0;
	virtual int getFeed() = 0;
	string getName() {
		return name;
	}
};

class Cat : public Animal {
	int value;
public:
	Cat(string name, int value):Animal(name) {
		this->value = value;
	}
	virtual string getCry() {
		return "야옹";
	}
	virtual int getFeed() {
		int total = 2 * value;
		return 2*value;
	}
	/* 생성자, 상속, 매개변수전달, 가상함수 구현을 코딩하여 완성하시오. 고양이는 하루 2끼 먹는다.*/

	/* ---------------------------------------------------------------------------------------- */
};

class Dog : public Animal {
	int value;
public:
	Dog(string name, int value):Animal(name) {
		this->value = value;
	}
	virtual string getCry() {
		return "멍멍";
	}
	virtual int getFeed() {
		return 3 * value;
	}

};

int main() {
	string name;
	int feedValue;

	cout << "고양이의 이름과 한끼 섭취량을 입력하시오. => ";
	cin >> name >> feedValue;
	Animal* cp = new Cat(name, feedValue);

	cout << "강아지의 이름과 한끼 섭취량을 입력하시오. => ";
	cin >> name >> feedValue;
	Animal* dp = new Dog(name, feedValue);
	cout << endl;

	cout << cp->getName() << " 소리는 " << cp->getCry() << "이고 하루 섭취량은 " << cp->getFeed() << "g이다. " << endl;
	cout << dp->getName() << " 소리는 " << dp->getCry() << "이고 하루 섭취량은 " << dp->getFeed() << "g이다. " << endl;

	cout << endl;
	delete cp;
	delete dp;
}