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
	p.push_back(new Stock("삼성전자", 70000, 0, 0));
	p.push_back(new Stock("카카오", 40000, 0, 0));
	p.push_back(new Stock("쿠팡", 10000, 0, 0));
	p.push_back(new Bitcoin("비트코인", 20000, 0, 0));
	p.push_back(new Bitcoin("이더리움", 3000, 0, 0));
	p.push_back(new Bitcoin("도지코인", 500, 0, 0));
};
Simulator::~Simulator() {
	cout << "\n####################################################################################################" << endl;
	cout << "Day " << day << " " << time << ":00" << endl;
	cout << "보유 금액: " << cash << endl << "자산: " << assets << "( " << assets / initial_cash * 100 - 100 << "%)\n" << endl;

	if (assets > initial_cash) cout << "\ngreat job!\n";
	else cout << "\nTry harder next time!\n";
	for (int i = 0; i < p.size(); i++) {
		delete p[i];
	}
};
void Simulator::proceed() {

	for (int i = 0; i < p.size(); i++) { //가격변동률 책정 및 가격 계산
		int new_rate = rand();
		if (i < 3) { //주식
			new_rate = new_rate % 21 - 10;
			if (time >= 9 && time <= 17) p[i]->setRate(new_rate); //장이 열릴 시간이면 적용
			else p[i]->setRate(0);
		}
		else {//비트코인
			new_rate = new_rate % 61 - 30;
			p[i]->setRate(new_rate);
		}
		p[i]->fluctuate();
	}
	assets = cash;
	for (int i = 0; i < p.size(); i++) {//자산 계산
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
	cout << "보유 금액: " << cash << endl << "자산: " << assets << "( " << assets / initial_cash * 100 - 100 << "%)\n" << endl;

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
			cout << "사실 상품 번호와 수량을 입력하세요" << endl;
			cin >> n >> q;
			if (!cin) {
				cin.clear();
				cin.ignore(4, '\n');
				throw 0.0;
			}
			if((1<=n&& n<=3)&&(time<9 || time>17)) throw "time_out"; //거래 가능 시간이 아닐 경우
			if (n < 1 || n>6) throw 'e'; //올바르지 않은 상품 번호
			if (cash - p[n - 1]->getPrice() * q < 0) throw n; //구매 가능 금액보다 더 많은 구매를 원할 경우
			else {
				p[n - 1]->setQuantity(p[n - 1]->getQuantity() + q); //보유 수량 늘림
				cash = cash - p[n - 1]->getPrice() * q; //보유 금액 줄임
				cout << n << "번 상품 " << q << "개를 " << p[n - 1]->getPrice()*q << "원에 구입했습니다.\n잔액 : " << cash << endl;
				break;
			}
		}
		catch (char e) {
			cout << "올바르지 않은 상품번호 입력입니다.\n" << endl;
		}
		catch (int n) {
			cout << "금액이 부족합니다.\n" << endl;
		}
		catch (double e) {
			cout << "올바르지 않은 입력입니다. 다시 입력해주세요\n" << endl;

		}
		catch (...) {
			cout << "거래 가능 시간이 아닙니다.\n" << endl;
		}
	}
}
void Simulator::sell() {
	int n, q;
	while (true) {
		try {
			cout << "파실 상품 번호와 수량을 입력하세요" << endl;
			cin >> n >> q;
			
			if (!cin) {
				cin.clear();
				cin.ignore(4, '\n');
				throw 0.0;
			}
			if ((1 <= n && n <= 3) && (time < 9 || time>17)) throw "time_out"; //거래 가능 시간이 아닐 경우
			if (n < 1 || n>6) throw 'e'; //올바르지 않은 상품 번호
			if (p[n - 1]->getQuantity() < q) throw n;//보유한 수량보다 판매를 원하는 수량이 많을 경우
			else {
				p[n - 1]->setQuantity(p[n - 1]->getQuantity() - q); //보유 수량 줄임
				cash = cash + p[n - 1]->getPrice() * q; //보유 금액 늘림
				cout << n << "번 상품 " << q << "개를 " << p[n - 1]->getPrice() * q << "원에 판매했습니다.\n잔액 : " << cash << endl;
				break;
			}
		}
		catch (char e) {
			cout << "올바르지 않은 상품번호 입력입니다.\n" << endl;
		}
		catch (int n) {
			cout << "보유하신 상품의 개수가 부족합니다.\n" << endl;
		}
		catch (double e) {
			cout << "올바르지 않은 입력입니다. 다시 입력해주세요\n" << endl;
		}
		catch (...) {
			cout << "거래 가능 시간이 아닙니다.\n" << endl;
		}
	}
}
void Simulator::pass() { }

void Simulator::start() {
	cout << "시작 금액을 설정해주세요 " << endl;
	cin >> initial_cash;
	cash = initial_cash;
	assets = initial_cash;
	do {
		info(); //현황자료 출력
		while (true) {
			try {
				cout << "\n작업을 선택해주세요\n1:구매 요청\n2: 판매요청\n3: 1시간 후 현황" << endl;
				cin >> choose;

				if (choose == 1) { buy(); break; }
				else if (choose == 2) {sell(); break;}
				else if (choose == 3) {pass(); break;}
				else throw choose;
			}
			catch (int choose) {
				cout << "올바르지 않은 입력입니다. 다시 입력해주세요." << endl;
			}
		}
		proceed();
	} while (day!=4);
	
};
