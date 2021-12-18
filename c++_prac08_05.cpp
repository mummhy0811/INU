#include<iostream>
//baseArray를 상속받아 큐처럼 작동하는 클래그를 작성하라.
//명품c++ 8장 연습문제 5번

using namespace std;

class BaseArray {
private:
	int capacity;
	int* mem;
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity; mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) {mem[index] = val;}
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue:public BaseArray {
	int head, tail;
	int len;
public:
	MyQueue(int capacity):BaseArray(capacity) {
		this->head = 0; //삽입할 위치는 head
		this->tail = -1; //tail+1위치에서 꺼내기
		this->len = 0; //초기 개수는 0
	}
	void enqueue(int n);
	int dequeue();
	int length() { return len; }
	int capacity() { return getCapacity(); }
};
void MyQueue::enqueue(int n) {
	if (len == capacity()) return; //큐가 꽉 찼으면 그냥 리턴
	put(head, n); //넣는다
	head++;
	head = head % capacity();
	len++;
}
int MyQueue::dequeue() {
	if (len == 0) return -1; //비어있으면 에러
	tail++;
	tail = tail % capacity();
	len--;
	return 	get(tail);
}

int main() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개 정수 입력>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "큐의 용량: " << mQ.capacity() << ", 큐의 크기: " << mQ.length() << endl;
	cout << "큐의 원소 순서대로 제거하여 출력>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << " ";
	}
	cout << endl << "큐의 현재 크기: " << mQ.length() << endl;
}
