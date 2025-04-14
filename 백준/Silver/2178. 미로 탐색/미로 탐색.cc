#include <iostream>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

int N, M;
queue<pair<int, int>> q;
stack<pair<int, int>> s;
int visited[101][101] = { 0 };
int grid[101][101];

void BFS() {
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, 1, -1 };
	q.push(make_pair(1, 1));
	visited[1][1] = 1;
	
	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];
			if (nowR <= 0 || nowR > N ||
				nowC <= 0 || nowC > M ||
				visited[nowR][nowC] != 0 ||
				grid[nowR][nowC] == 0)
				continue;
			q.push(make_pair(nowR, nowC));
			visited[nowR][nowC] = visited[curR][curC] + 1;
		}
	}
}

int main() {
	cin >> N >> M;
	getchar();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char input = getchar();
			if (input == '1') {
				grid[i][j] = 1;
			}
			else
				grid[i][j] = 0;
		}
		getchar();
	}
	BFS();

	cout << visited[N][M];


	return 0;
}