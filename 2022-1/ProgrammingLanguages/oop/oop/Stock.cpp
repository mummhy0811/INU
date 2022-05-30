#include <iostream>
#include <iomanip>
#include "Stock.h"

using namespace std;

Stock::Stock(string name, double price, int quantity, int rate) :Product(name, price, quantity, rate) {
	
}
int Stock::fluctuate() {
	setPrice(getPrice() + getPrice() * getRate() * 0.01);
	return 0;
};
void Stock::print() {
	cout << left << setw(15) << "�ֽĻ�ǰ : " << left << setw(10) << getName() << " | ���� ���� : " 
		<< right << setw(7) << getPrice() << " | ���� ����: " << right << setw(3) << getQuantity() << " | ���� : " << getRate() << "%" << endl;

};
