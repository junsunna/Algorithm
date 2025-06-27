#include <iostream>
#include <deque>
using namespace std;

int grid[101][101] = { 0 };
int N, A, D;
char dir[10001] = { 0 };
int timer = 0;

void move() {
	int dr[4] = { 0, 1, 0, -1 };
	int dc[4] = { 1, 0, -1, 0 };
	int curR = 1, curC = 1;
	int curD = 0;
	deque<pair<int, int>> dq;
	dq.push_back({ curR, curC });
	if (dir[0] == 'R') {
		curD = (curD + 1) % 4;
	}
	else if (dir[0] == 'D') {
		curD = (curD + 3) % 4;
	}

	while (1) {
		int nowR = curR + dr[curD];
		int nowC = curC + dc[curD];
		if (nowR < 1 || nowR > N ||
			nowC < 1 || nowC > N) {
			timer++;
			return;
		}
		dq.push_back({ nowR, nowC });
		if (grid[nowR][nowC] == 2) {
			curR = nowR;
			curC = nowC;
			grid[curR][curC] = 1;
		}
		else if (grid[nowR][nowC] == 0) {
			curR = nowR;
			curC = nowC;
			grid[curR][curC] = 1;
			grid[dq.front().first][dq.front().second] = 0;
			dq.pop_front();
		}
		else {
			timer++;
			return;
		}
		timer++;
		if (dir[timer] == 'L') {
			curD = (curD + 3) % 4;
		}
		else if (dir[timer] == 'D') {
			curD = (curD + 1) % 4;
		}
		
	}
}

int main() {
	cin >> N >> A;
	for (int i = 0; i < A; i++) {
		int r, c;
		cin >> r >> c;
		grid[r][c] = 2;
	}
	cin >> D;
	for (int i = 0; i < D; i++) {
		int input;
		char d;
		cin >> input >> d;
		dir[input] = d;
	}

	move();
	cout << timer;

	return 0;
}