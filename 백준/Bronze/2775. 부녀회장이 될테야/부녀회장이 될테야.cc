#include <iostream>
using namespace std;

int main() {
    int T, k, n;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int dp[15][15] = {0};
        cin >> k >> n;
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int j = 1; j <= k; j++) {
            dp[j][1] = dp[j - 1][1];
            for (int l = 2; l <= n; l++) {
                dp[j][l] = dp[j][l - 1] + dp[j - 1][l];
            }

        }
        cout << dp[k][n] << "\n";
    }

    return 0;
}