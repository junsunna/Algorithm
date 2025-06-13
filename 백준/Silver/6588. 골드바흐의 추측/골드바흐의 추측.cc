#include <iostream>
using namespace std;
#define MAX 1000001

bool prime[MAX];

void initPrime() {
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
	prime[0] = prime[1] = true;
	initPrime();
	while (cin >> N) {
		if (N == 0) break;
		int a, b;
		bool result = false;
		for (int i = 3; i <= N / 2; i += 2) {
			if (!prime[i] && !prime[N - i]) {
				a = i; b = N - i;
				result = true;
				break;
			}
		}
		if (result)
			cout << N << " = " << a << " + " << b << '\n';
		else
			cout << "Goldbach's conjecture is wrong." << '\n';
	}
	return 0;
}