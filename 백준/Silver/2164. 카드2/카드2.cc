#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	queue<int> card;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		card.push(i);
	}
	for (int i = 0; i < N - 1; i++) {
		card.pop();
		card.push(card.front());
		card.pop();
	}
	cout << card.front();
	return 0;
}