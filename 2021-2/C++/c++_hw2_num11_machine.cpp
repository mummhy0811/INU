#include <iostream>
#include "container.h"
#include "machine.h"
using namespace std;
void CoffeeVendingMachine::fill() { //3개 모두 채우기
	for (int i = 0; i < 3; i++) {
		tong[i].fill();
	}
	show();
}
void CoffeeVendingMachine::selectEspresso() {
	if (tong[0].getSize() == 0 || tong[1].getSize() == 0) 	cout << "원료가 부족합니다." << endl;
	else {
		tong[0].consume();
		tong[1].consume();
		cout << "에스프레소 드세요" << endl;
	}
}
void CoffeeVendingMachine::selectAmericano() {
	if (tong[0].getSize() == 0 || tong[1].getSize() <= 1) 	cout << "원료가 부족합니다." << endl;
	else {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		cout << "아메리카노 드세요" << endl;
	}
}
void CoffeeVendingMachine::selectSugarCoffee() {
	if (tong[0].getSize() == 0 || tong[1].getSize() <= 1 || tong[2].getSize() == 0) 	cout << "원료가 부족합니다." << endl;
	else {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
		cout << "설탕커피 드세요" << endl;
	}
}
void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
}
void CoffeeVendingMachine::run() {
	int choose;
	while (true) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>>";
		cin >> choose;
		if (choose > 5 || choose < 1) {
			cout << "잘못된 메뉴입니다. 다시 눌러주세요" << endl;
			continue;
		}
		switch (choose) {
		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		}
	}
}