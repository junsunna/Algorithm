#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000][1000];

int main() {
	string a, b;
	cin >> a >> b;
	bool toggle = false;
	for (int j = 0; j < a.size(); j++) {
		for (int i = 0; i < b.size(); i++) {
			if (toggle) {
				dp[j][i] = 1;
			}
			else {
				if (a[j] == b[i]) {
					dp[j][i] = 1;
					toggle = true;
				}
			}
		}
		if (toggle) break;
	}
	for (int i = 1; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (j - 1 < 0) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
	}
	cout << dp[a.size()-1][b.size()-1];
	return 0;
}