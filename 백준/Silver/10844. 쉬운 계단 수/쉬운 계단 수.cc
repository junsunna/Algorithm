#include <iostream>
using namespace std;

const int MOD = 1000000000;
int main() {
    int n;
    cin >> n;

    int dp[101][10] = { 0 };

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }
            if (j < 9)
            {
                dp[i][j] += dp[i - 1][j + 1];
            }
            dp[i][j] %= MOD;
        }
    }
    int sum = 0;
    for (int i = 0; i <= 9; i++) {
        sum = (sum + dp[n][i]) % MOD;
    }
    cout << sum;
    return 0;
}