#ifndef EXP_H //���� ������ ����
#define EXP_H

class Exp {
	int exp;
	int base;
public:
	Exp() { base = 1; exp = 1; }
	Exp(int b) { base = b; exp = 1; }
	Exp(int b, int e) {  exp = e; base = b;
	}

	int getBase() { return base; }
	int getExp() { return exp; }
	int getValue();
	bool equals(Exp b);

};
#endif
