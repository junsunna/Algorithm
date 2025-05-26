#include <iostream>
#include <vector>
using namespace std;

int R, C;
char grid[21][21];
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };
bool alphaUsed[26];
int maxDepth = 0;

void dfs(int r, int c, int depth) {
	maxDepth = max(maxDepth, depth);
	alphaUsed[grid[r][c] - 'A'] = true;

	for (int i = 0; i < 4; i++) {
		int nowR = r + dr[i];
		int nowC = c + dc[i];
		if (nowR < 1 || nowC < 1 ||
			nowR > R || nowC > C) continue;
		char nextChar = grid[nowR][nowC];
		if (alphaUsed[nextChar - 'A']) continue;

		dfs(nowR, nowC, depth + 1);
	}
	alphaUsed[grid[r][c] - 'A'] = false;
}


int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= C; j++) {
			grid[i][j] = input[j - 1];
		}
	}
	dfs(1, 1, 1);
	cout << maxDepth;

	return 0;
}