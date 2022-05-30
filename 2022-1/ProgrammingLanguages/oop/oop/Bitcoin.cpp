#include <iostream>
#include <iomanip>
#include "Bitcoin.h"
#include "Product.h"

using namespace std;

Bitcoin::Bitcoin(string name, double price, int quantity, int rate):Product(name, price,quantity,rate) {
	
}
int Bitcoin::fluctuate() {

	setPrice(getPrice() + getPrice() * getRate() * 0.01);
	return 0;
};
void Bitcoin::print() {
	cout <<left << setw(15)<<"가상화폐상품 : " << left << setw(10) << getName()<< " | 현재 가격 : " 
		<< right<<setw(7) << getPrice()<< " | 보유 수량: " << right << setw(3) << getQuantity() << " | 변동 : "<<getRate()<<"%"<<endl;
};
