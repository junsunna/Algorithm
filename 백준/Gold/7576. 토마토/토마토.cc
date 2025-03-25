#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int grid[1001][1001];
int N, M, cnt = -1;
int dr[4] = { -1, 1, 0, 0 }; // 상 하 좌 우
int dc[4] = { 0, 0, -1, 1 }; 
queue<pair<int, int>> q;

void BFS() {
	while (!q.empty()) {
		int size = q.size();

		for (int j = 0; j < size; j++) {
			pair<int, int> curRC = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nowR = curRC.first + dr[i];
				int nowC = curRC.second + dc[i];
				if (nowR < 0 || nowR >= N ||
					nowC < 0 || nowC >= M) continue;
				if (grid[nowR][nowC]) continue;
				q.push(make_pair(nowR, nowC));
				grid[nowR][nowC] = 1;
			}
		}
		cnt++;
	}
}

int main() {
	int all = -1;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 0) {
				all = 1;
			}
			else if (grid[i][j] == 1) {
				q.push(make_pair(i, j));
			}
			else {
				grid[i][j] = 1;
			}
		}
	}
	if (!all) cout << 0;
	BFS();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << cnt;

	return 0;
}