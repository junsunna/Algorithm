#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int grid[500][500];
bool visited[500][500] = { 0 };
int result = 0;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };


void dfs(int curR, int curC, int depth, int sum) {
	if (depth == 4) {
		result = max(result, sum);
		return;
	}
	if (depth == 2) {
		for (int i = 0; i < 4; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];
			if (nowR < 0 || nowC < 0 || nowR >= N || nowC >= M || visited[nowR][nowC] == 1) continue;
			visited[nowR][nowC] = true;
			dfs(curR, curC, depth + 1, sum + grid[nowR][nowC]);
			visited[nowR][nowC] = false;
		}
	}
	for (int i = 0; i < 4; i++) {
		int nowR = curR + dr[i];
		int nowC = curC + dc[i];
		if (nowR < 0 || nowC < 0 || nowR >= N || nowC >= M || visited[nowR][nowC] == 1) continue;
		visited[nowR][nowC] = true;
		dfs(nowR, nowC, depth + 1, sum + grid[nowR][nowC]);
		visited[nowR][nowC] = false;
	}
}

void find() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			dfs(i, j, 1, grid[i][j]);
			visited[i][j] = false;

		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}
	find();
	cout << result;
	return 0;
}