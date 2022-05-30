#ifndef PRODUCT_H 
#define PRODUCT_H 
#include <string>
using namespace std;

class Product {
	int quantity, rate; //보유 수량, 변동률
	double price; //현재 가격
	string name; //이름
public:
	Product(string name, double price, int quantity, int rate);
	virtual int fluctuate();
	virtual void print();
	string getName();
	double getPrice();
	int getQuantity(), getRate();
	void setName(string name), setPrice(double price), setQuantity(int quantity), setRate(int rate);
};

#endif


