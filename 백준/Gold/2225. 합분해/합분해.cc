#include <iostream>
using namespace std;

int dp[201][201] = { 0 };

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 1 || j == 0) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}
	cout << dp[K][N];

	return 0;
}