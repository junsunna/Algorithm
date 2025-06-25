#include <iostream>
using namespace std;

bool grid[51][51] = { 0 };
bool clean[51][51] = { 0 };
int N, M;
int r, c, d;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int cnt = 0;

void move() {
	int curR = r;
	int curC = c;
	while (1) {
		if (clean[curR][curC] == 0) {
			clean[curR][curC] = 1;
			cnt++;
		}
		bool result = false;
		for (int i = 0; i < 4; i++) {
			d = (d + 4 - 1) % 4;
			int nowR = curR + dr[d];
			int nowC = curC + dc[d];
			if (nowR < 0 || nowC < 0 ||
				nowR >= N || nowC >= M || 
				grid[nowR][nowC] == 1 || clean[nowR][nowC] == 1) continue;
			curR = nowR;
			curC = nowC;
			result = true;
			break;
		}
		if (!result) {
			int nowR = curR + dr[(d + 2) % 4];
			int nowC = curC + dc[(d + 2) % 4];
			if (nowR < 0 || nowC < 0 ||
				nowR >= N || nowC >= M || grid[nowR][nowC] == 1) {
				return;
			}
			curR = nowR;
			curC = nowC;
		}
	}
}

int main() {
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}
	move();
	cout << cnt;

	return 0;
}