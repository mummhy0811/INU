#include<iostream>
//명품c++ 8장 실습문제 4번
using namespace std;
class Point {
	int p1, p2;
public:
	Point(int p1 = 0, int p2 = 0) { this->p1 = p1; this->p2 = p2; }
	void setPoint(int p1, int p2) { this->p1 = p1; this->p2 = p2; }
	int getp1() { return p1; }
	int getp2() { return p1; }
};

class ColorPoint:public Point {
	string color;
public:
	ColorPoint(int p1=0, int p2=0, string color = "BLACK") :Point(p1, p2) {
		this->color = color;
	}
	void setColor(string color) { this->color = color; }
	void show() {
		cout << color << "색으로 (" << getp1() << ", " << getp2() << ")에 위치한 점입니다." << endl;
	}
};
int main() {
	ColorPoint zeroPoint;
	zeroPoint.show();

	ColorPoint cp(5, 5);
	cp.setColor("BLUE");
	cp.setPoint(10, 20);
	cp.show();
}
