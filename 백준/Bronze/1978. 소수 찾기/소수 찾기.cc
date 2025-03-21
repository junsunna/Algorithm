#include <iostream>
#include <math.h>
using namespace std;

bool findPrimeNumber(int n) {
	if (n == 1)
		return false;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int N, num, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (findPrimeNumber(num))
			cnt++;
	}
	cout << cnt;

	return 0;
}