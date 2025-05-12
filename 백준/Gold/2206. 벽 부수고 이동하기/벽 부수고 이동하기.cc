#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M;
char grid[1001][1001];
int dist[1001][1001][2];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ 1, 1, 0 });
	dist[1][1][0] = 1;

	while (!q.empty()) {
		int curR = get<0>(q.front());
		int curC = get<1>(q.front());
		int broken = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];

			if (nowR < 1 || nowR > N ||
				nowC < 1 || nowC > M) continue;
			
			if (grid[nowR][nowC] == '0' && dist[nowR][nowC][broken] == 0) {
				dist[nowR][nowC][broken] = dist[curR][curC][broken] + 1;
				q.push({ nowR,nowC,broken });
			}

			if (grid[nowR][nowC] == '1' && broken == 0 && dist[nowR][nowC][1] == 0) {
				dist[nowR][nowC][1] = dist[curR][curC][0] + 1;
				q.push({ nowR, nowC, 1 });
			}
		}
		
	}
	int d0 = dist[N][M][0], d1 = dist[N][M][1];
	if (d0 && d1) return min(d0, d1);
	else if (d0) return d0;
	else if (d1) return d1;
	else return -1;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	string line;
	for (int i = 1; i <= N; i++) {
		cin >> line;
		for (int j = 1; j <= M; j++) {
			grid[i][j] = line[j - 1];
		}
	}

	cout << bfs() << "\n";

	return 0;
}