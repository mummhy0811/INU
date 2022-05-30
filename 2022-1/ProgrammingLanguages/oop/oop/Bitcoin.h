#ifndef BITCOIN_H 
#define BITCOIN_H 
#include <string>
#include "Product.h"
using namespace std;

class Bitcoin: public Product {
public:
	Bitcoin(string name, double price, int quantity, int rate);
	virtual int fluctuate() override;
	virtual void print() override;
};

#endif