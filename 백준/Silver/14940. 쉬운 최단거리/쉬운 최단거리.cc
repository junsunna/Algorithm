#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n, m;
int grid[1001][1001] = { 0 };
int visited[1001][1001] = { 0 };
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

void dfs() {
	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextR = curR + dr[i];
			int nextC = curC + dc[i];
			if (nextR >= 0 && nextR < n &&
				nextC >= 0 && nextC < m &&
				visited[nextR][nextC] == 0 &&
				grid[nextR][nextC] != 0) {
				visited[nextR][nextC] = 1;
				grid[nextR][nextC] = grid[curR][curC] + 1;
				q.push(make_pair(nextR, nextC));
			}
		}
	}

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 2) {
				q.push(make_pair(i, j));
				visited[i][j] = 1;
				grid[i][j] = 0;
			}
		}
	}
	dfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && grid[i][j] != 0) {
				grid[i][j] = -1;
			}
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}