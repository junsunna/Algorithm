#include <iostream>
#include <algorithm>
using namespace std;
int dp[100000] = { 0 };

int main() {
	int n;
	cin >> n;
	cin >> dp[0];
	int maxSum = dp[0];
	for (int i = 1; i < n; i++) {
		int num;
		cin >> num;
		dp[i] = max(dp[i - 1] + num, num);
		maxSum = max(maxSum, dp[i]);
	}
	cout << maxSum;

	return 0;
}