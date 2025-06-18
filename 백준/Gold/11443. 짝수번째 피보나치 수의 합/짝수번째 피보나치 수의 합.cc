#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

vector<long long> matMulVec(vector<vector<long long>>& a, vector<long long> b) {
	vector<long long> res(2);
	res[0] = (a[0][0] * b[0] + a[0][1] * b[1]) % MOD;
	res[1] = (a[1][0] * b[0] + a[1][1] * b[1]) % MOD;
	return res;
}

vector<vector<long long>> matMul(vector<vector<long long>> a, vector<vector<long long>> b) {
	vector<vector<long long>> res(2, vector<long long>(2));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
	return res;
}

vector<vector<long long>> matPow(vector<vector<long long>> a, long long n) {
	vector<vector<long long>> res = { {1, 0}, {0, 1} };
	while (n > 0) {
		if (n % 2 == 1) res = matMul(res, a);
		a = matMul(a, a);
		n /= 2;
	}
	return res;
}

long long fib(long long n) {
	if (n == 0) return 0;
	if (n % 2 == 0) n++;
	vector<vector<long long>> a = { {1, 1}, {1, 0} };
	vector<vector<long long>> an = matPow(a, n - 1);

	vector<long long> init = { 1, 0 };
	vector<long long> result = matMulVec(an, init);
	return result[0] - 1;
}

int main() {
	long long N;
	cin >> N;
	cout << fib(N);
	return 0;
}