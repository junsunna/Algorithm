#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N;
char grid[101][101];
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };

void bfs(int startR, int startC, bool visited[101][101], int toggle) {
	queue<pair<int, int>> q;
	q.push(make_pair(startR, startC));
	visited[startR][startC] = 1;
	char start = grid[startR][startC];
	if (toggle && start == 'B')
		toggle = 0;


	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];
			if (nowR < 1 || nowR > N ||
				nowC < 1 || nowC > N || visited[nowR][nowC] == 1) continue;
			if (toggle) {
				if (grid[nowR][nowC] == 'B')
					continue;
			}
			else {
				if (grid[nowR][nowC] != start)
					continue;
			}
			q.push(make_pair(nowR, nowC));
			visited[nowR][nowC] = 1;
		}
	}

}


int main() {
	bool visitedRGB[101][101] = { 0 };
	bool visited[101][101] = { 0 };
	cin >> N;
	getchar();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			grid[i][j] = getchar();
		}
		getchar();
	}
	int resultNormal = 0, resultRGB = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j, visited, 0);
				resultNormal++;
			}
			if (visitedRGB[i][j] == 0) {
				bfs(i, j, visitedRGB, 1);
				resultRGB++;
			}
		}
	}
	cout << resultNormal << " " << resultRGB;


	return 0;
}