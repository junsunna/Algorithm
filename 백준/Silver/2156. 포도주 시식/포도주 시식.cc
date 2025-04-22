#include <iostream>
#include <algorithm>
using namespace std;

int n, index = 2;
int arr[10001];
int dp[10001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]), dp[i - 1]);
	}
	
	cout << dp[n];

	return 0;
}