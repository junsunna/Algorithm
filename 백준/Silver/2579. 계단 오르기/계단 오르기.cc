#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> stairs(n);
	vector<int> dp(n);


	for (int i = 0; i < n; i++) {
		cin >> stairs[i];
	}

	dp[0] = stairs[0];
	if (n > 1) dp[1] = stairs[0] + stairs[1];
	if (n > 2) dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}
	cout << dp[n-1] << endl;

	return 0;
}