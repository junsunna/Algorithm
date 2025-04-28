#include <iostream>
int main(){int N;std::cin>>N;long dp[91][2]={0};dp[1][1]=1;for(int i=2;i<=N;i++){dp[i][0]=dp[i-1][0]+dp[i-1][1];dp[i][1]=dp[i-1][0];}std::cout<<dp[N][0]+dp[N][1];return 0;}