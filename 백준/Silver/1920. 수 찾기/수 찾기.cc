#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, num;
	unordered_set<int> numset;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		numset.insert(num);
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		cout << (numset.find(num) != numset.end() ? 1 : 0) << '\n';
	}
	return 0;
}