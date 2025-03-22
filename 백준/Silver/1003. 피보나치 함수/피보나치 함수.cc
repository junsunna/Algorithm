#include <iostream>
using namespace std;

struct zeroOne {
	int zero;
	int one;
};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		zeroOne f0 = { 1, 0 }, f1 = { 0, 1 }, f2 = { 0, 0 };
		if (N == 0) {
			cout << f0.zero << " " << f0.one << "\n";
			continue;
		}
		else if (N == 1) {
			cout << f1.zero << " " << f1.one << "\n";
			continue;
		}
		for (int i = 2; i <= N; i++) {
			f2.zero = f0.zero + f1.zero;
			f2.one = f0.one + f1.one;
			f0.zero = f1.zero;
			f0.one = f1.one;
			f1.zero = f2.zero;
			f1.one = f2.one;
		}
		cout << f2.zero << " " << f2.one << "\n";
	}

	return 0;
}