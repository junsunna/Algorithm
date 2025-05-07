#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int grid[9][9];
int visited[9][9];
int dr[4] = {0, 0, 1, -1};
int dc[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> selected;
vector<pair<int, int>> points;
vector<int> result;

void bfs(int firstR, int firstC) {
	queue<pair<int, int>> q;
	q.push(make_pair(firstR, firstC));

	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];

			if (nowR < 1 || nowR > N ||
				nowC < 1 || nowC > M || visited[nowR][nowC] != 0) continue;
			q.push(make_pair(nowR, nowC));
			visited[nowR][nowC] = 2;
		}
	}
}

void backtracking(int start, int depth) {
	if (depth == 3) {
		memcpy(visited, grid, sizeof(grid));
		for (auto a : selected) {
			visited[a.first][a.second] = 1;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (visited[i][j] == 2) {
					bfs(i, j);
				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (visited[i][j] == 0) cnt++;
			}
		}
		result.push_back(cnt);
		return;
	}
	for (int i = start; i < points.size(); i++) {
		selected.push_back(points[i]);
		backtracking(i + 1, depth + 1);
		selected.pop_back();

	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 0)
				points.push_back(make_pair(i, j));
		}
	}
	backtracking(0, 0);
	if (!result.empty())
		cout << *max_element(result.begin(), result.end()) << '\n';
	else
		cout << "0\n";
	return 0;
}