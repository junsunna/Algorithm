#include <iostream>
#include <vector>
using namespace std;
#define MAX 4000001

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
		vector<int> primes;
		for (int i = 2; i <= N; i++) {
			if (!prime[i]) primes.push_back(i);
		}
		int cnt = 0;
		for (int i = 0; i < primes.size(); i++) {
			int sum = 0;
			for (int j = i; j < primes.size(); j++) {
				sum += primes[j];
				if (sum >= N) break;
			}
			if (sum == N) cnt++;
			
		}
		cout << cnt << '\n';

	}
	return 0;
}