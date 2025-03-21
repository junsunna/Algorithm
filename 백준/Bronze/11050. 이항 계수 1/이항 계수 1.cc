#include <iostream>
using namespace std;

int factorial(int n) {
	if (n <= 0) return 1;
	int sum = n;
	for (int i = 2; i < n; i++) {
		sum *= i;
	}
	return sum;
}

int main() {
	int N, K;
	cin >> N >> K;
	int a = factorial(N), b = factorial(K), c = factorial(N - K);

	cout << a / (b * c);
	return 0;
}