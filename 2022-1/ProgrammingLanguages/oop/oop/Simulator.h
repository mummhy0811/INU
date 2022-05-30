#include <vector>
#include "Product.h"

#ifndef SIMULATOR_H 
#define SIMULATOR_H 
class Simulator {
	int time, day, choose;
	double assets, cash, initial_cash;
	std::vector<Product*> p;
public:
	void proceed();
	void start();
	Simulator();
	~Simulator();
	void buy();
	void sell();
	void pass();
	void info();
};

#endif


