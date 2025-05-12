#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int T, N;
int grid[301][301];
int dr[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dc[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int R, C;

void bfs(int startR, int startC) {
	queue<pair<int, int>> q;
	grid[startR][startC] = 0;
	q.push(make_pair(startR, startC));

	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];
			if (nowR < 1 || nowR > N ||
				nowC < 1 || nowC > N ||
				grid[nowR][nowC] != 0) continue;
				
			
			q.push(make_pair(nowR, nowC));
			grid[nowR][nowC] = grid[curR][curC] + 1;
		}
	}
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				grid[i][j] = 0;
			}
		}
		cin >> R >> C;
		int startR, startC;
		cin >> startR >> startC;
		if (startR == R && startC == C) {
			cout << 0 << "\n";
			continue;
		}
		bfs(startR+1, startC+1);
		cout << grid[R+1][C+1] << "\n";
	}

	return 0;
}