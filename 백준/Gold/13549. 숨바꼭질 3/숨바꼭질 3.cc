#include <iostream>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int result = 0;
int dir[3] = { 0, 1, -1 };
int dp[1000001];

void bfs() {
	fill(dp, dp + 100001, -1);
	int time = 0;
	queue<int> q;
	dp[N] = 0;
	q.push(N);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == K) return;

		for (int i = 0; i < 3; i++) {
			int now = i == 0 ? cur * 2 : cur + dir[i];

			if (now < 0 || now > 100000) continue;

			if (i == 0 && dp[now] != -1 && dp[now] < dp[cur]) continue;
			else if (i != 0 && dp[now] != -1 && dp[now] < dp[cur] + 1) continue;

			if (i == 0)
				dp[now] = dp[cur];
			else
				dp[now] = dp[cur] + 1;
			
			q.push(now);

		}
	}
}

int main() {
	cin >> N >> K;
	bfs();
	cout << dp[K] << "\n";

	return 0;
}