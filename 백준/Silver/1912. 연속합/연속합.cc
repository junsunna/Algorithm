#include <iostream>
using namespace std;
int dp[100000] = { 0 };

int main() {
	int n;
	cin >> n;
	cin >> dp[0];
	int max = dp[0];
	for (int i = 1; i < n; i++) {
		int num;
		cin >> num;
		int a = dp[i - 1];
		if (a < 0) {
			if (num > 0) {
				dp[i] = num;
				continue;
			}
		}
		if (dp[i - 1] + num > 0) {
			dp[i] = dp[i - 1] + num;
		}
		else {
			dp[i] = num;
		}
        if (dp[i] > max)
            max = dp[i];
	}
	cout << max;

	return 0;
}