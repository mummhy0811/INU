#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;





int main() {
	string name;
	int score;

	map<string, int> std;
	map<string, int>::iterator it;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "��° �л��� �̸��� ������ �Է��Ͻÿ� --> ";
		cin >> name >> score;
		std[name] = score;
	}

	/* map�� ���������̳ʰ� �ƴϹǷ� �Է¼����� ��µ��� �ʰ� �⺻ ���ķ� ��µȴ�. */
	/* map�� ù��° key(�̸�)�� iter-> first�� �ι�° value(����)�� iter-> second�� ��� ���� */
	
	cout << endl<< "�л��� �̸��� ����" << endl;
	for (it = std.begin(); it != std.end(); it++) {
		string n=it->first;
		int sc = it->second;
		cout << n << "\t" << sc<<endl;
			}

	cout << endl;
	return 0;
}