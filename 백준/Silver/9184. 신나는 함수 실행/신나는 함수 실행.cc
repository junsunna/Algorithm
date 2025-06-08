#include <iostream>
#include <math.h>
using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return dp[20][20][20];
	return dp[a][b][c];
}

void bdp() {
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			for (int k = 1; k <= 20; k++) {
				if (i < j && j < k) {
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k-1] - dp[i][j-1][k];
				}
				else {
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			dp[0][i][j] = 1;
			dp[i][0][j] = 1;
			dp[i][j][0] = 1;
		}
	}
	bdp();

	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
	}
	return 0;
}