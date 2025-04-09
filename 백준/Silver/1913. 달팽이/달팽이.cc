#include <iostream>
using namespace std;

int grid[1000][1000];
int N, target, targetX, targetY;


void roop() {
	cin >> N >> target;

	int x, y;
	// 상우하좌
	int dr[4] = { -1, 0, 1, 0 };
	int dc[4] = { 0, 1, 0, -1 };
	x = (N - 1) / 2;
	y = (N - 1) / 2;
	int value = 1;
	int dIndex = 0; // 방향 인덱스 drdc
	int moveCount = 1; // 움직임 횟수 한계
	int moveIndex = 0; // 현재 움직임 횟수
	if (target == 1) {
		targetX = x;
		targetY = y;
	}
	grid[x][y] = value++;
	while (value <= N * N) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < moveCount; j++) {
				x += dr[dIndex];
				y += dc[dIndex];
				grid[x][y] = value;
				if (value == N * N) return;
				if (value == target) {
					targetX = x;
					targetY = y;
				}
				value++;
			}
			dIndex = (dIndex + 1) % 4;
		}
		moveCount++;
	}
}

int main() {
	roop();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}

	cout << targetX +1  << " " << targetY +1;
	return 0;
}