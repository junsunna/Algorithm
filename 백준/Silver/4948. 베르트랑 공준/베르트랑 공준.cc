#include <iostream>
using namespace std;

int prime[246913];

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int N;
	prime[0] = prime[1] = true;
	for (int i = 2; i * i <= 246912; i++) {
		if (prime[i] == 0) {
			for (int j = i * i; j <= 246912; j += i) {
				prime[j] = true;
			}
		}
	}
	while (true) {
		cin >> N;
		if (N == 0) return 0;

		int cnt = 0;
		for (int i = N + 1; i <= N * 2; i++) {
			if (!prime[i]) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}