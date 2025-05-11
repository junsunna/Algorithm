#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N, M;
char grid[51][51];
bool visited[51][51];
int dr[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dc[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int cnt = 0;

void bfs(int firstR, int firstC) {
	queue<pair<int, int>> q;
	q.push(make_pair(firstR, firstC));
	visited[firstR][firstC] = true;

	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];

			if (nowR < 1 || nowR > N ||
				nowC < 1 || nowC > M ||
				grid[nowR][nowC] == '0' ||
				visited[nowR][nowC] == true) continue;
			visited[nowR][nowC] = true;
			q.push(make_pair(nowR, nowC));

		}
	}
}

int main() {
	while (true) {
		vector<pair<int, int>> v;
		cnt = 0;
		cin >> M >> N;
		if (N == 0 && M == 0) break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> grid[i][j];
				visited[i][j] = 0;
				if (grid[i][j] == '1')
					v.push_back(make_pair(i, j));
			}
		}
		for (auto p : v) {
			if (visited[p.first][p.second] == true) continue;
			bfs(p.first, p.second);
			cnt++;
		}
		cout << cnt << "\n";
	}


	return 0;
}