#include<iostream>
using namespace std;

class Circle {
	int radius; 
	string name; 
public:
	void setCircle(string name, int radius); 
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
	
};
void Circle::setCircle(string n, int r) {
	this->name = n;
	this->radius = r;
}

class CircleManager {
	Circle* p; 
	int size; 
public:
	CircleManager(int size); 
	~CircleManager() { delete[] p; }
	void searchByName(); 
	void searchByArea(); 
};

CircleManager::CircleManager(int s) {
	size = s;
	string n = ""; int r = 0;
	p = new Circle[s];
	for (int i = 0; i < s; i++) {
		cout << "�� " << i + 1 << "�� �̸��� ������ >>";
		cin >> n >> r;
		p[i].setCircle(n, r);
	}
}
void CircleManager::searchByArea() {
	int min;
	cout << "�ּ� ������ ������ �Է��ϼ��� >>";
	cin >> min;
	cout << min << "���� ū ���� �˻��մϴ�." << endl;
	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > min) {
			cout << p[i].getName() << "�� ������ " << p[i].getArea() << ",";
		}
	}
}
void CircleManager::searchByName() {
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >>";
	string name;
	cin >> name;
	for (int i = 0; i < size; i++) {
		if (name == p[i].getName()) {
			cout << name << "�� ������ " << p[i].getArea() << endl;
			break;
		}
	}
}

int main() {
	int num;
	cout << "���� ���� >>";
	cin >> num;
	CircleManager c(num);
	c.searchByName();
	c.searchByArea();
}