#include<iostream>
using namespace std;
//abstractstack을 상속받아 정수를 푸시, 팝하는 intstack클래스를 만들고, 사용 사례를 보여라
//명품c++ 9장 실습문제 6번
class AbstractStack {
public:
	virtual bool push(int n) = 0; //스택에 n을 푸시. 스택이 full이면 false리턴
	virtual bool pop(int& n) = 0; //스택에서 팝한 정수를 n에 저장하고 스택이 empty이면 false 리턴
	virtual int size() = 0; //현재 스택에 저장된 정수의 개수 리턴
};

class IntStack : public AbstractStack {
	int tos, capacity;
	int* mem;

public:
	IntStack(int capacity = 100) { this->capacity = capacity; this->tos = -1; mem = new int[capacity]; }
	~IntStack() { delete[] mem; }
	bool push(int n);
	bool pop(int& n);
	int size() { return tos; }
	void show();
};
bool IntStack::push(int n) {
	if (tos == capacity - 1) return false;
	tos++;
	mem[tos] = n;
	return true;
}
bool IntStack::pop(int& n) {
	if (tos == -1)return false;
	n= mem[tos];
	tos--;
	return true;
}
void IntStack::show() {
	cout << "현재 스택의 값 >>  ";
	for (int i = 0; i <= tos; i++) {
		cout << mem[i] << " ";
	}
	cout << endl;
}
int main() {
	IntStack st(100);
	int num=0, n = 0;
	cout << "스택에 넣을 값의 개수를 입력하세요>> ";
	cin >> n;
	cout << "스택에 넣을 값을 차례대로 입력하세요 >> ";
	for (int i = 0; i < n; i++) { 
		cin >> num;
		st.push(num); 
	}
	st.show(); //스택 값 출력
	cout << "스택을 순서대로 pop합니다 >>  " ;
	for (int i = 0; st.size()!= -1; i++) {
		st.pop(n);
		cout << n << " ";
	}
}
