#include<iostream>
//통계를 내는 statistics클래스를 만들려고 한다. 데이터는 statistics클래스 내부에 int배열을 동적으로 할당받아 유지한다. 필요한 연산자 함수를 작성하라.
//명품C++ 7장 실습문제 10번
using namespace std;
class Statistics {
	int* arr;
	int size;
	int index;
public:
	Statistics() {
		size = 5;
		index = 0;
		arr = new int[size];
	}
	~Statistics() {
		delete[]arr;
	}
	bool operator!();
	Statistics& operator << (int n); //삽입
	void operator >> (int& n); //출력
	void operator~();
};

bool Statistics:: operator!() {
	if (index == 0) return true;
	return false;
}
Statistics& Statistics:: operator<<(int n) {
	if (index == size - 1) {
		int* tmp = new int[size * 2];
		for (int i = 0; i < index; i++) {
			tmp[i] = arr[i];
		}
		delete[] arr;
		arr = tmp;
		size = size * 2;
	}
	arr[index] = n;
	index++;
	return *this;
}
void Statistics:: operator>>(int & n) {
	int sum = 0;
	for (int i = 0; i < index; i++) {
		sum += arr[i];
	}
	n = sum / index;
}
void Statistics:: operator~() {
	for (int i = 0; i < index; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	Statistics stat;
	if (!stat)cout << "현재 통계 데이타가 없습니다." << endl;

	int x[5];
	cout << "5개의 정수를 입력하세요>> ";
	for (int i = 0; i < 5; i++) cin >> x[i]; //x[i]에 정수 입력
	for (int i = 0; i < 5; i++) stat << x[i]; //값을 통계 객체에 삽입
	stat << 100 << 200; //값 삽입
	~stat; //통계 데이터 모두 출력
	 
	int avg;
	stat >> avg;
	cout << "avg= " << avg << endl;
}
