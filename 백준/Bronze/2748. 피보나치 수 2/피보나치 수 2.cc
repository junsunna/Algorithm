#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long dp[91]; // 범위 초과 방지
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2]; // 그 전 값 + 그 전전 값
    }
    cout << dp[n];
    return 0;
}