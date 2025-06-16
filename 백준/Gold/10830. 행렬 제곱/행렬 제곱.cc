#include <iostream>
#include <vector>
using namespace std;

long long N, B;

vector<vector<long long>> matMul(vector<vector<long long>>& a, vector<vector<long long>>& b) {
	int n = a.size();
	vector<vector<long long>> res(n, vector<long long>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				res[i][j] = (res[i][j] + (a[i][k] * b[k][j])) % 1000;
	return res;
}

vector<vector<long long>> matPow(vector<vector<long long>> a, long long power) {
	vector<vector<long long>> res(N, vector<long long>(N));
	for (int i = 0; i < N; i++) res[i][i] = 1;

	while (power > 0) {
		if (power % 2 == 1) res = matMul(res, a);
		a = matMul(a, a);
		power /= 2;
	}
	return res;
}

int main() {
	cin >> N >> B;
	vector<vector<long long>> grid(N, vector<long long>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	vector<vector<long long>> res = matPow(grid, B);
	for (vector<long long> a : res) {
		for (long long b : a) {
			cout << b << ' ';
		}
		cout << '\n';
	}
	return 0;
}