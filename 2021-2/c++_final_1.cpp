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
		cout << i + 1 << "번째 학생의 이름과 성적을 입력하시오 --> ";
		cin >> name >> score;
		std[name] = score;
	}

	/* map은 순서컨테이너가 아니므로 입력순서로 출력되지 않고 기본 정렬로 출력된다. */
	/* map의 첫번째 key(이름)은 iter-> first로 두번째 value(점수)는 iter-> second로 출력 가능 */
	
	cout << endl<< "학생의 이름과 점수" << endl;
	for (it = std.begin(); it != std.end(); it++) {
		string n=it->first;
		int sc = it->second;
		cout << n << "\t" << sc<<endl;
			}

	cout << endl;
	return 0;
}