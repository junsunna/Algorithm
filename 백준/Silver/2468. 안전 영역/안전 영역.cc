#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int result = 1;
int N;
int grid[101][101];
bool visited[101][101];
queue<pair<int, int>> q;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int cnt = 0;

void bfs(int depth, int startR, int startC) {
	if (visited[startR][startC] || grid[startR][startC] <= depth) return;
	q.push(make_pair(startR, startC));
	visited[startR][startC] = true;
	cnt++;

	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];

			if (nowR < 1 || nowR > N ||
				nowC < 1 || nowC > N ||
				visited[nowR][nowC] ||
				grid[nowR][nowC] <= depth) continue;
			q.push(make_pair(nowR, nowC));
			visited[nowR][nowC] = true;
		}
	}
}

int main() {
	int min = 100, max = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> grid[i][j];
			visited[i][j] = 0;
			if (min > grid[i][j])
				min = grid[i][j];
			if (max < grid[i][j])
				max = grid[i][j];
		}
	}

	for (int i = 0; i <= max; i++) {
		cnt = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				visited[j][k] = false;
				if (grid[j][k] <= i)
					visited[j][k] = true;
			}
		}
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (!visited[j][k])
					bfs(i, j, k);
			}
		}
		if (cnt > result) result = cnt;
		
	}
	cout << result;

	return 0;
}