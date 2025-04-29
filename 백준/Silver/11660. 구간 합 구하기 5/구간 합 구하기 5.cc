#include <iostream>
#include <algorithm>
using namespace std;

int dp[1025][1025];
int arr[1025][1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (i == 1 && j == 1) {
				dp[i][j] = arr[i][j];
			}
			else {
				if (i == 1) {
					dp[i][j] = dp[i][j - 1] + arr[i][j];
				}
				else if (j == 1) {
					dp[i][j] = dp[i - 1][j] + arr[i][j];
				}
				else {
					dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i-1][j-1]) + arr[i][j];
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == 1 && b == 1) {
			cout << dp[c][d] << "\n";
		}
		else if (a == 1) {
			cout << dp[c][d] - dp[c][b - 1] << "\n";
		}
		else if (b == 1) {
			cout << dp[c][d] - dp[a - 1][d] << "\n";
		}
		else {
			cout << dp[c][d] - (dp[a - 1][d] + dp[c][b - 1] -
				dp[a - 1][b - 1]) << "\n";
		}
	}

	return 0;
}