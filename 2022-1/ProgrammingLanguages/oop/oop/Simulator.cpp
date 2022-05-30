#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "Simulator.h"
#include "Bitcoin.h"
#include "Stock.h"

using namespace std;

Simulator::Simulator() {
	time = 9; day=1; assets =0.0, cash =0.0, choose=1, initial_cash =0.0;
	p.reserve(6);
	p.push_back(new Stock("�Ｚ����", 70000, 0, 0));
	p.push_back(new Stock("īī��", 40000, 0, 0));
	p.push_back(new Stock("����", 10000, 0, 0));
	p.push_back(new Bitcoin("��Ʈ����", 20000, 0, 0));
	p.push_back(new Bitcoin("�̴�����", 3000, 0, 0));
	p.push_back(new Bitcoin("��������", 500, 0, 0));
};
Simulator::~Simulator() {
	cout << "\n####################################################################################################" << endl;
	cout << "Day " << day << " " << time << ":00" << endl;
	cout << "���� �ݾ�: " << cash << endl << "�ڻ�: " << assets << "( " << assets / initial_cash * 100 - 100 << "%)\n" << endl;

	if (assets > initial_cash) cout << "\ngreat job!\n";
	else cout << "\nTry harder next time!\n";
	for (int i = 0; i < p.size(); i++) {
		delete p[i];
	}
};
void Simulator::proceed() {

	for (int i = 0; i < p.size(); i++) { //���ݺ����� å�� �� ���� ���
		int new_rate = rand();
		if (i < 3) { //�ֽ�
			new_rate = new_rate % 21 - 10;
			if (time >= 9 && time <= 17) p[i]->setRate(new_rate); //���� ���� �ð��̸� ����
			else p[i]->setRate(0);
		}
		else {//��Ʈ����
			new_rate = new_rate % 61 - 30;
			p[i]->setRate(new_rate);
		}
		p[i]->fluctuate();
	}
	assets = cash;
	for (int i = 0; i < p.size(); i++) {//�ڻ� ���
		assets=assets+p[i]->getPrice()* p[i]->getQuantity();
	}
	if (time == 23) {
		day++; time = 0;
	}
	else { time++; }
};

void Simulator::info() {
	cout << "\n####################################################################################################" << endl;
	cout << "Day " << day << " " << time << ":00" << endl;
	cout << "���� �ݾ�: " << cash << endl << "�ڻ�: " << assets << "( " << assets / initial_cash * 100 - 100 << "%)\n" << endl;

	for (int i = 0; i < p.size(); i++)
	{
		cout << i + 1 << " ";
		p[i]->print();
	}
}

void Simulator::buy() {
	int n=NULL, q= NULL;
	while (true) {
		try {
			cout << "��� ��ǰ ��ȣ�� ������ �Է��ϼ���" << endl;
			cin >> n >> q;
			if (!cin) {
				cin.clear();
				cin.ignore(4, '\n');
				throw 0.0;
			}
			if((1<=n&& n<=3)&&(time<9 || time>17)) throw "time_out"; //�ŷ� ���� �ð��� �ƴ� ���
			if (n < 1 || n>6) throw 'e'; //�ùٸ��� ���� ��ǰ ��ȣ
			if (cash - p[n - 1]->getPrice() * q < 0) throw n; //���� ���� �ݾ׺��� �� ���� ���Ÿ� ���� ���
			else {
				p[n - 1]->setQuantity(p[n - 1]->getQuantity() + q); //���� ���� �ø�
				cash = cash - p[n - 1]->getPrice() * q; //���� �ݾ� ����
				cout << n << "�� ��ǰ " << q << "���� " << p[n - 1]->getPrice()*q << "���� �����߽��ϴ�.\n�ܾ� : " << cash << endl;
				break;
			}
		}
		catch (char e) {
			cout << "�ùٸ��� ���� ��ǰ��ȣ �Է��Դϴ�.\n" << endl;
		}
		catch (int n) {
			cout << "�ݾ��� �����մϴ�.\n" << endl;
		}
		catch (double e) {
			cout << "�ùٸ��� ���� �Է��Դϴ�. �ٽ� �Է����ּ���\n" << endl;

		}
		catch (...) {
			cout << "�ŷ� ���� �ð��� �ƴմϴ�.\n" << endl;
		}
	}
}
void Simulator::sell() {
	int n, q;
	while (true) {
		try {
			cout << "�Ľ� ��ǰ ��ȣ�� ������ �Է��ϼ���" << endl;
			cin >> n >> q;
			
			if (!cin) {
				cin.clear();
				cin.ignore(4, '\n');
				throw 0.0;
			}
			if ((1 <= n && n <= 3) && (time < 9 || time>17)) throw "time_out"; //�ŷ� ���� �ð��� �ƴ� ���
			if (n < 1 || n>6) throw 'e'; //�ùٸ��� ���� ��ǰ ��ȣ
			if (p[n - 1]->getQuantity() < q) throw n;//������ �������� �ǸŸ� ���ϴ� ������ ���� ���
			else {
				p[n - 1]->setQuantity(p[n - 1]->getQuantity() - q); //���� ���� ����
				cash = cash + p[n - 1]->getPrice() * q; //���� �ݾ� �ø�
				cout << n << "�� ��ǰ " << q << "���� " << p[n - 1]->getPrice() * q << "���� �Ǹ��߽��ϴ�.\n�ܾ� : " << cash << endl;
				break;
			}
		}
		catch (char e) {
			cout << "�ùٸ��� ���� ��ǰ��ȣ �Է��Դϴ�.\n" << endl;
		}
		catch (int n) {
			cout << "�����Ͻ� ��ǰ�� ������ �����մϴ�.\n" << endl;
		}
		catch (double e) {
			cout << "�ùٸ��� ���� �Է��Դϴ�. �ٽ� �Է����ּ���\n" << endl;
		}
		catch (...) {
			cout << "�ŷ� ���� �ð��� �ƴմϴ�.\n" << endl;
		}
	}
}
void Simulator::pass() { }

void Simulator::start() {
	cout << "���� �ݾ��� �������ּ��� " << endl;
	cin >> initial_cash;
	cash = initial_cash;
	assets = initial_cash;
	do {
		info(); //��Ȳ�ڷ� ���
		while (true) {
			try {
				cout << "\n�۾��� �������ּ���\n1:���� ��û\n2: �Ǹſ�û\n3: 1�ð� �� ��Ȳ" << endl;
				cin >> choose;

				if (choose == 1) { buy(); break; }
				else if (choose == 2) {sell(); break;}
				else if (choose == 3) {pass(); break;}
				else throw choose;
			}
			catch (int choose) {
				cout << "�ùٸ��� ���� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
			}
		}
		proceed();
	} while (day!=4);
	
};
