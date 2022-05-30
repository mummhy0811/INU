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
	cout << left << setw(15) << "주식상품 : " << left << setw(10) << getName() << " | 현재 가격 : " 
		<< right << setw(7) << getPrice() << " | 보유 수량: " << right << setw(3) << getQuantity() << " | 변동 : " << getRate() << "%" << endl;

};
