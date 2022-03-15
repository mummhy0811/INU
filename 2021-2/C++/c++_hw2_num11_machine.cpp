#include <iostream>
#include "container.h"
#include "machine.h"
using namespace std;
void CoffeeVendingMachine::fill() { //3�� ��� ä���
	for (int i = 0; i < 3; i++) {
		tong[i].fill();
	}
	show();
}
void CoffeeVendingMachine::selectEspresso() {
	if (tong[0].getSize() == 0 || tong[1].getSize() == 0) 	cout << "���ᰡ �����մϴ�." << endl;
	else {
		tong[0].consume();
		tong[1].consume();
		cout << "���������� �弼��" << endl;
	}
}
void CoffeeVendingMachine::selectAmericano() {
	if (tong[0].getSize() == 0 || tong[1].getSize() <= 1) 	cout << "���ᰡ �����մϴ�." << endl;
	else {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		cout << "�Ƹ޸�ī�� �弼��" << endl;
	}
}
void CoffeeVendingMachine::selectSugarCoffee() {
	if (tong[0].getSize() == 0 || tong[1].getSize() <= 1 || tong[2].getSize() == 0) 	cout << "���ᰡ �����մϴ�." << endl;
	else {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
		cout << "����Ŀ�� �弼��" << endl;
	}
}
void CoffeeVendingMachine::show() {
	cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << endl;
}
void CoffeeVendingMachine::run() {
	int choose;
	while (true) {
		cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���)>>";
		cin >> choose;
		if (choose > 5 || choose < 1) {
			cout << "�߸��� �޴��Դϴ�. �ٽ� �����ּ���" << endl;
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