#include <iostream>
#include <math.h>
using namespace std;

int dp[51][51][51];

int w(int a, int b, int c) {
	if (dp[a][b][c] != -1) return dp[a][b][c];
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (a < b && b < c) return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}

int main() {
	for (int i = 0; i <= 50; i++) {
		for (int j = 0; j <= 50; j++) {
			for (int k = 0; k <= 50; k++) {
				
				dp[i][j][k] = -1;
				if (i > 20 || j > 20 || k > 20)
					dp[i][j][k] = 1048576;
				else if (i <= j && i <= k) {
					dp[i][j][k] = pow(2, i);
				}
			}
		}
	}
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		if (a < 1 || b < 1 || c < 1) {
			cout << "w(" << a << ", " << b << ", " << c << ") = " << 1 << "\n";
			continue;
		}
		int result = w(a, b, c);
		cout << "w(" << a << ", " << b << ", " << c << ") = " << result << "\n";
	}
	return 0;
}