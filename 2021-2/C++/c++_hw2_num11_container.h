#ifndef CONTAINER_H
#define CONTAINER_H

class Container {
	int size;
public:
	Container() { size = 10; }
	void fill();
	void consume();
	int getSize();
};

#endif 