#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int dp[5001] = { 0 };

int main() {
	int N;
	cin >> N;
	
	dp[3] = 1;
	dp[5] = 1;
	for (int i = 5; i <= N; i++) {
		if (dp[i - 5] != 0) {
			dp[i] = dp[i - 5] + 1;
		} else if (dp[i - 3] != 0) {
			dp[i] = dp[i - 3] + 1;
		}
	}
	if (dp[N] == 0)
		cout << -1;
	else 
		cout << dp[N];

	

	return 0;
}