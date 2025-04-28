#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int T[16], P[16], dp[17] = { 0 };
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        if (i + T[i] - 1 <= N) {
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        }
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << *max_element(dp, dp + N + 2) << endl;
    return 0;
}