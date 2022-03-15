#include<iostream>
using namespace std;
//BaseArray클래스를 상속받아 스택으로 작동하는 Mystack 클래스를 작성하라
//명품c++ 8장 연습문제 6번
class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack : public BaseArray { //basearray상속받음
	int tos;
public:
	MyStack(int capacity=100) : BaseArray(capacity) {
		tos = -1;
	}
	void push(int n);
	int pop();
	int length() { return tos + 1; }
	int capacity() { return getCapacity(); }
};
void MyStack::push(int n) {
	if (tos == getCapacity() - 1) {
		cout << "스택이 꽉찼습니다." << endl; return;
	}
	tos++;
	put(tos, n);//값 집어넣음
}
int MyStack::pop(){
	if (tos == -1) {
		cout << "스택이 비어있습니다" << endl; return -1;
	}
	int num = get(tos);
	tos--;
	return num;
}

int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "스택용량: " << mStack.capacity() << " , 스택크기: " << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>>";
	while (mStack.length() != 0) {
		cout << mStack.pop() << " ";
	}
	cout << endl << "스택의 현재 크기: " << mStack.length() << endl;
}
