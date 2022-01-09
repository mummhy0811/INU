#include<iostream>
using namespace std;
#include "container.h"

void Container::fill() { //최대량으로 채우기
	this->size = 10;
}
void Container::consume() { //1만큼 소모
	this->size = this->size - 1;
}
int Container::getSize() { //현재 크기 리턴
	return size;
}