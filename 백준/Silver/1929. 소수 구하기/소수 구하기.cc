#include <iostream>
using namespace std;

bool prime[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int M, N;
	cin >> M >> N;
	prime[0] = prime[1] = true;
	for (int i = 2; i * i <= N; i++) {
		if (prime[i] == 0) {
			for (int j = i * i; j <= N; j += i) {
				prime[j] = true;
			}
		}
	}
	for (int i = M; i <= N; i++) {
		if (!prime[i]) cout << i << '\n';
	}
	return 0;
}