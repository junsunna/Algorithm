#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001];
int P[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	dp[1] = P[1];
	dp[2] = max(dp[1] * 2, P[2]);
	for (int i = 3; i <= N; i++) {
		dp[i] = P[i];
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[j] + dp[i - j], dp[i]);
		}
	}
	cout << dp[N];

	return 0;
}