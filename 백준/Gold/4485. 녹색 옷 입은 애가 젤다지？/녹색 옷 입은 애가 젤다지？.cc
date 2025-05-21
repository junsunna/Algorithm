#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
#define INF 1e9

int N;
int grid[126][126];
int dist[126][126];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0, };

int dijkstra() {
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
	pq.push({ grid[1][1], 1, 1 });
	dist[1][1] = grid[1][1];

	while (!pq.empty()) {
		tuple<int, int, int> cur = pq.top();
		pq.pop();
		int curCost = get<0>(cur);
		int curR = get<1>(cur);
		int curC = get<2>(cur);
		
		if (curR == N && curC == N)
			return dist[N][N];
		
		for (int i = 0; i < 4; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];

			if (nowR < 1 || nowC < 1 ||
				nowR > N || nowC > N) continue;

			int nowCost = curCost + grid[nowR][nowC];

			if (nowCost < dist[nowR][nowC]) {
				pq.push({ nowCost, nowR, nowC });
				dist[nowR][nowC] = nowCost;
			}
		}
		
	}
	return -1;
}

int main() {
	int cnt = 0;
	while (true) {
		cnt++;
		cin >> N;
		if (N == 0) return 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> grid[i][j];
				dist[i][j] = INF;
			}
		}
		cout << "Problem " << cnt << ": " << dijkstra() << "\n";
	}

	return 0;
}