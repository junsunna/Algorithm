#include <iostream>
#include <vector>
using namespace std;

int M, N;
int board[501][501];
int dp[501][501];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int dfs(int r, int c) {
	if (r == M - 1 && c == N - 1) return 1;

	if (dp[r][c] != -1) return dp[r][c];

	dp[r][c] = 0;

	for (int i = 0; i < 4; i++) {
		int nowR = r + dr[i];
		int nowC = c + dc[i];

		if (nowR >= 0 && nowR < M && nowC >= 0 && nowC < N && board[nowR][nowC] < board[r][c]) {
			dp[r][c] += dfs(nowR, nowC);
		}
	}
	return dp[r][c];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0);
	return 0;
}