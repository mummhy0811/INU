#include <iostream>
using namespace std;

class Stack {
	int size;
	int* mem; // ���� �޸� �Ҵ�. ���� ����
	int tos; // top of stack. -1�̸� ������ �����
public:
	Stack(int size = 10) {
		this->size = size;
		mem = new int[size]; // int [10] ���� �Ҵ�.
		tos = -1; // ������ �������
	}
	~Stack() {
		delete[] mem;
	}
	bool operator!();
	Stack& operator>>(int& n);
	Stack& operator << (int n); //����
	friend Stack& operator++(Stack&op);
	
};

Stack& operator++ (Stack& op) {
	for (int i = 0; i <= op.tos; i++) {
		op.mem[i] += 1;
	}
	return op;
}


Stack& Stack:: operator<<(int n) { //Ǫ��
	if (tos == size - 1) {
		return *this;
	}
	tos++;
	mem[tos] = n;
	return *this;
}

Stack& Stack::operator >> (int& n) { // ��
	if (tos == -1) {
		return *this;
	}
	n = mem[tos]; // top�� �ִ� ���� �� ����
	tos--; // ���� top ����
	return *this;
}

bool Stack::operator ! () { // ��� ������ true ����
	if (tos == -1)
		return true;
	else
		return false;
}

int main() {
	Stack stack;
	stack << 10 << 20 << 30; // 3, 5, 10�� ������� Ǫ��
	++stack;
	int x;
	while (true) {
		if (!stack) break; // ���� empty
		stack >> x; // ������ ž�� �ִ� ���� ��
		cout << x << ' ';
	}
	cout << endl;
}

