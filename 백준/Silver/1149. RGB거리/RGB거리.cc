#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dp[1001][4] = {0};
vector<int> v[1001];

int main() {
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		v[i].push_back(r);
		v[i].push_back(g);
		v[i].push_back(b);
	}
	dp[1][1] = v[1][0];
	dp[1][2] = v[1][1];
	dp[1][3] = v[1][2];
	for (int i = 2; i <= N; i++) {
		dp[i][1] = v[i][0] + min(dp[i - 1][2], dp[i - 1][3]);
		dp[i][2] = v[i][1] + min(dp[i - 1][1], dp[i - 1][3]);
		dp[i][3] = v[i][2] + min(dp[i - 1][1], dp[i - 1][2]);
	}
	cout << min(min(dp[N][1], dp[N][2]), min(dp[N][2], dp[N][3]));
	return 0;
}