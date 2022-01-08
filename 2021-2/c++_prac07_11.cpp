#include <iostream>
//스택 클래스 stack을 만들고 푸시용으로 <<연산자를, 팝을 위해>>연산자를, 비어있는 스택이닞 알기 위해 !연산자를 작성하라.
//명품c++ 7장 실습문제 11번

using namespace std;

class Stack {
	int tos;
	int* mem;
	int size;
public:
	Stack(int size=10) {
		this->size = size;
		tos = -1;
		mem = new int[size];
	}
	~Stack() {
		delete[] mem;
	}
	Stack& operator<<( int a);
	Stack& operator>>(int& a);
	bool operator!();
};

Stack& Stack:: operator<< ( int a) {
	if (tos == size - 1) {
		cout << "stack이 꽉 참"; return *this;
	}
	tos ++ ;
	mem[tos] = a;
	return *this;
}

Stack& Stack:: operator>> (int& a) {
	if (tos == - 1) {
		cout << "stack이 비었음"; return *this;
	}
	a = mem[tos];
	tos --;
	return *this;
}
bool Stack::operator!() {
	if (tos == -1) return true;
	else return false;
}


int main()
{
	Stack stack;
	stack << 3 << 5 << 10;
	int x;
	while (true) {
		if (!stack) break;
		stack >> x;
		cout << x << " ";
	}
	cout << endl;
}
