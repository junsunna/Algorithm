#include <iostream>
using namespace std;

int main() {
	int N, K, cnt = 0;
	int coins[11];
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> coins[i];
	}
	for (int i = N; i > 0; i--) {
		if (K >= coins[i]) {
			int count = (K / coins[i]);
			K = K - (coins[i] * count);
			cnt += count;
		}
	}
	cout << cnt;
	return 0;
}