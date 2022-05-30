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
	cout <<left << setw(15)<<"����ȭ���ǰ : " << left << setw(10) << getName()<< " | ���� ���� : " 
		<< right<<setw(7) << getPrice()<< " | ���� ����: " << right << setw(3) << getQuantity() << " | ���� : "<<getRate()<<"%"<<endl;
};
