#include <iostream>
using namespace std;
#define MAX 1000001

bool prime[MAX];

void initPrime() {
	prime[0] = prime[1] = true;
	for (int i = 2; i * i < MAX; i++) {
		if (!prime[i]) {
			for (int j = i * i; j < MAX; j += i) {
				prime[j] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	initPrime();
	while (cin >> N) {
		if (N == 0) break;
		for (int i = 3; i <= N / 2; i += 2) {
			if (!prime[i] && !prime[N - i]) {
				cout << N << " = " << i << " + " << N - i << '\n';
				break;
			}
		}
	}
	return 0;
}