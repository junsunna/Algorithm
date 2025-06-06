#include <iostream>
using namespace std;

int dp[1001][1001];
int N, K;

int main() {
	cin >> N >> K;
	for (int i = 0; i <= N; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}

	cout << dp[N][K];
	return 0;
}