#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, M, N, K, cnt = 0;
int grid[50][50] = { 0 };
vector<pair<int, int>> v;
queue<pair<int, int>> q;
int dr[4] = { -1, 1, 0, 0 }; // 상 하 좌 우
int dc[4] = { 0, 0, -1, 1 };

void BFS() {
	for (auto& p : v) {
		if (grid[p.first][p.second] == 1) {
			q.push(p);
			grid[p.first][p.second] = 0;
			break;
		}
	}
	
	while (!q.empty()) {
		pair<int, int> curRC = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nowR = curRC.first + dr[i];
			int nowC = curRC.second + dc[i];
			if (nowR < 0 || nowR >= N ||
				nowC < 0 || nowC >= M) continue;
			if (!grid[nowR][nowC]) continue;
			q.push(make_pair(nowR, nowC));
			grid[nowR][nowC] = 0;
		}
	}
}

int main() {
	cin >> T;
	while (T--) {
		cnt = 0;
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			int r, c;
			cin >> c >> r;
			grid[r][c] = 1;
			v.push_back(make_pair(r, c));
		}
		for (auto& p : v) {
			if (grid[p.first][p.second] == 1) {
				BFS();
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}