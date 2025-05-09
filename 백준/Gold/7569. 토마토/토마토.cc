#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int M, N, H;
int grid[101][101][101];
int visited[101][101][101] = { 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };
int dr[6] = { 0, 0, 1, -1, 0, 0 };
int dc[6] = { 1, -1, 0, 0, 0, 0 };

queue<pair<pair<int, int>, int>> q;

void bfs() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int firstH = q.front().first.first;
	int firstN = q.front().first.second;
	int firstM = q.front().second;
	q.pop();
	q.push(make_pair(make_pair(firstH, firstN), firstM));
	while (!q.empty()) {
		int curH = q.front().first.first;
		int curN = q.front().first.second;
		int curM = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nowH = curH + dh[i];
			int nowN = curN + dr[i];
			int nowM = curM + dc[i];
			if (nowH < 1 || nowH > H ||
				nowN < 1 || nowN > N ||
				nowM < 1 || nowM > M) continue;
			if (visited[nowH][nowN][nowM] == -1) {
				continue;
			}
			else if (visited[nowH][nowN][nowM] >= 1) {
				if (visited[curH][curN][curM] + 1 >= visited[nowH][nowN][nowM])
					continue;
			}
			q.push(make_pair(make_pair(nowH, nowN), nowM));
			visited[nowH][nowN][nowM] = visited[curH][curN][curM] + 1;
		}
	}
}

int main() {
	bool isTomato = false;
	cin >> M >> N >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> grid[i][j][k];
				if (grid[i][j][k] == 0)
					isTomato = true;
				else if (grid[i][j][k] == -1)
					visited[i][j][k] = -1;
				else {
					q.push(make_pair(make_pair(i, j), k));
					visited[i][j][k] = 1;
				}
			}
		}
	}
	if (!isTomato) {
		cout << 0;
		return 0;
	}
	bfs();
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (visited[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (visited[i][j][k] > max) {
					max = visited[i][j][k];
				}
			}
		}
	}
	cout << max - 1;

	return 0;
}