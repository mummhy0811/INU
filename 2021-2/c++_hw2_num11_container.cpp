#include<iostream>
using namespace std;
#include "container.h"

void Container::fill() { //�ִ뷮���� ä���
	this->size = 10;
}
void Container::consume() { //1��ŭ �Ҹ�
	this->size = this->size - 1;
}
int Container::getSize() { //���� ũ�� ����
	return size;
}