#include <iostream>
#include <string>
#include <map>
using namespace std;

class Animal {
protected:
	string name; // ������ �̸�
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
		return "�߿�";
	}
	virtual int getFeed() {
		int total = 2 * value;
		return 2*value;
	}
	/* ������, ���, �Ű���������, �����Լ� ������ �ڵ��Ͽ� �ϼ��Ͻÿ�. ����̴� �Ϸ� 2�� �Դ´�.*/

	/* ---------------------------------------------------------------------------------------- */
};

class Dog : public Animal {
	int value;
public:
	Dog(string name, int value):Animal(name) {
		this->value = value;
	}
	virtual string getCry() {
		return "�۸�";
	}
	virtual int getFeed() {
		return 3 * value;
	}

};

int main() {
	string name;
	int feedValue;

	cout << "������� �̸��� �ѳ� ���뷮�� �Է��Ͻÿ�. => ";
	cin >> name >> feedValue;
	Animal* cp = new Cat(name, feedValue);

	cout << "�������� �̸��� �ѳ� ���뷮�� �Է��Ͻÿ�. => ";
	cin >> name >> feedValue;
	Animal* dp = new Dog(name, feedValue);
	cout << endl;

	cout << cp->getName() << " �Ҹ��� " << cp->getCry() << "�̰� �Ϸ� ���뷮�� " << cp->getFeed() << "g�̴�. " << endl;
	cout << dp->getName() << " �Ҹ��� " << dp->getCry() << "�̰� �Ϸ� ���뷮�� " << dp->getFeed() << "g�̴�. " << endl;

	cout << endl;
	delete cp;
	delete dp;
}