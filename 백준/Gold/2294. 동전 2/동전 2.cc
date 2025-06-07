#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];
int dp[10001] = { 0 };

int main() {
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= K; i++) {
		dp[i] = 1e9;
	}
	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = arr[i]; j <= K; j++) {
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	if (dp[K] == 1e9)
		cout << "-1";
	else cout << dp[K];
	return 0;
}