#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001] = { 0 };
int weight[101], value[101];

int main() {
	int n, k;
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int w = 1; w <= k; w++) {
			if (weight[i] > w) {
				dp[i][w] = dp[i - 1][w];
			}
			else {
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i]] + value[i]);
			}
		}
	}
	cout << dp[n][k];

	return 0;
}