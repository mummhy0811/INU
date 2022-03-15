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
		cout << "원 " << i + 1 << "의 이름과 반지름 >>";
		cin >> n >> r;
		p[i].setCircle(n, r);
	}
}
void CircleManager::searchByArea() {
	int min;
	cout << "최소 면적을 정수로 입력하세요 >>";
	cin >> min;
	cout << min << "보다 큰 원을 검색합니다." << endl;
	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > min) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ",";
		}
	}
}
void CircleManager::searchByName() {
	cout << "검색하고자 하는 원의 이름 >>";
	string name;
	cin >> name;
	for (int i = 0; i < size; i++) {
		if (name == p[i].getName()) {
			cout << name << "의 면적은 " << p[i].getArea() << endl;
			break;
		}
	}
}

int main() {
	int num;
	cout << "원의 개수 >>";
	cin >> num;
	CircleManager c(num);
	c.searchByName();
	c.searchByArea();
}