#include <iostream>
#include "Product.h"

using namespace std;

Product::Product(string name, double price, int quantity, int rate) {
	this->quantity = quantity;
	this->rate = rate;
	this->price= price;
	this->name= name;
};
string Product::getName() { return name; }
double Product::getPrice() { return price; }
int Product::getQuantity() { return quantity; }
int Product::getRate() { return rate; }
void Product::setName(string name) { this->name = name; }
void Product::setPrice(double price) { this->price = price; }
void Product::setQuantity(int quantity) { this->quantity = quantity; }
void Product::setRate(int rate) { this->rate = rate; }

int Product::fluctuate() {
	return 0;
};
void Product::print() {

};
