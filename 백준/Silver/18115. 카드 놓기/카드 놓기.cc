#include <iostream>
#include <deque>
using namespace std;
int skill[1000000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int N;
	cin >> N;
	deque<int> dq;

	for (int i = 1; i <= N; i++)
		cin >> skill[i];

	int card = 1;
	for (int i = N; i > 0; i--) {
		if (skill[i] == 1) {
			dq.push_back(card);
		}
		else if (skill[i] == 2) {
			int top = dq.back();
			dq.pop_back();
			dq.push_back(card);
			dq.push_back(top);
		}
		else {
			dq.push_front(card);
		}
		card++;
	}
	for (int i = N; i > 0; i--) {
		int num = dq.back();
		dq.pop_back();
		cout << num << ' ';
	}
	cout << '\n';
	return 0;
}