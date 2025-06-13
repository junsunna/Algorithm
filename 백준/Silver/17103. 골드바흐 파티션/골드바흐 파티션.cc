#include <iostream>
using namespace std;
#define MAX 1000001


bool prime[MAX];
int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int T, N;
	cin >> T;
	prime[0] = prime[1] = true;
	for (int i = 2; i * i < MAX; i++) {
		if (!prime[i]) {
			for (int j = i * i; j < MAX; j += i) {
				prime[j] = true;
			}
		}
	}
	while (T--) {
		cin >> N;
		int cnt = 0;
		for (int i = N/2; i >= 2; i--) {
			if (!prime[i] && !prime[N - i]) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}