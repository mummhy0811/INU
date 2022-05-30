#ifndef PRODUCT_H 
#define PRODUCT_H 
#include <string>
using namespace std;

class Product {
	int quantity, rate; //���� ����, ������
	double price; //���� ����
	string name; //�̸�
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


