#ifndef STOCK_H 
#define STOCK_H 
#include <string>
#include "Product.h"
using namespace std;

class Stock : public Product {
public:
	Stock(string name, double price, int quantity, int rate);
	virtual int fluctuate() override;
	virtual void print() override;
};

#endif