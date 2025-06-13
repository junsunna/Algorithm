#include <iostream>
using namespace std;

bool prime[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int T, N;
	cin >> T;
	prime[0] = prime[1] = true;
	for (int i = 2; i * i < 10001; i++) {
		if (!prime[i]) {
			for (int j = i * i; j < 10001; j += i) {
				prime[j] = true;
			}
		}
	}
	while (T--) {
		cin >> N;
		int a, b;
		for (int i = N/2; i >= 2; i--) {
			if (!prime[i] && !prime[N - i]) {
				a = i; b = N-i;
				break;
			}
		}
		cout << a << ' ' << b << '\n';
	}
	return 0;
}