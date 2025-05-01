#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000][2];
int dp[100000][2];


int main() {
	int T;
	cin >> T;
	int n;
	for (int i = 0; i < T; i++) {
		cin >> n;
		
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= n; k++) {	
				cin >> arr[k][j];
			}
		}
		dp[0][0] = 0;
		dp[0][1] = 0;
		dp[1][0] = arr[1][0];
		dp[1][1] = arr[1][1];

		for (int j = 2; j <= n; j++) {
			dp[j][0] = max(dp[j - 2][1] + arr[j][0], dp[j - 1][1] + arr[j][0]);
			dp[j][1] = max(dp[j - 2][0] + arr[j][1], dp[j - 1][0] + arr[j][1]);
		}
		cout << max(dp[n][0], dp[n][1]) << "\n";
	}

	return 0;
}