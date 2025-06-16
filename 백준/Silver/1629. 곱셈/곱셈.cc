#include <iostream>
using namespace std;

int A, B, C;

long long power(long long a, long long b, long long c) {
	if (b == 0) return 1;
	long long half = power(a, b / 2, c);
	long long result = (half * half) % c;
	if (b % 2 == 1)
		return (result *a) % c;
	return result;
}

int main() {
	cin >> A >> B >> C;
	cout << power(A, B, C);
	return 0;
}