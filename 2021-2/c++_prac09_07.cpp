#include<iostream>
//shape클래스를 상속받아 타원을 표현하는 oval, rect, triangular클래스를 작성하라.
//명품c++ 9장 실습문제 7번

using namespace std;
class Shape {
protected:
	int w, h;
	string name;
public:
	Shape(string name = "", int w = 1, int h = 1) {
		this->name = name; this->w = w; this->h = h;
	}
	virtual double getArea()=0;
	string getName() { return name; }
};
class Oval : public Shape {
public:
	Oval(string name , int r1, int r2 ) :Shape(name, r1, r2){}
	double getArea() {
		return 3.14 * w * h;
	}
};

class Rect : public Shape {

public:
	Rect(string name, int w, int h) :Shape(name, w,  h) { }
	double getArea() {
		return w * h;
	}
};
class Triangular : public Shape {
public:
	Triangular(string name, int w, int h):Shape(name, w, h){}
	double getArea() {
		return w * h / 2;
	}
};
int main() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);
	for (int i = 0; i < 3; i++) {
		cout << p[i]->getName() << "넓이는 " << p[i]->getArea() << endl;
		
	}
	for (int i = 0; i < 3; i++)delete p[i];
}
