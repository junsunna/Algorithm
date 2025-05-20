#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9

int N, M;
int grid[101][101];
int dist[101][101];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

int dijkstra() {
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
	pq.push({ 0, 1, 1 });
	dist[1][1] = 0;

	while (!pq.empty()) {
		tuple<int, int, int> cur = pq.top();
		pq.pop();
		int cost = get<0>(cur);
		int curR = get<1>(cur);
		int curC = get<2>(cur);

		if (curR == N && curC == M) return cost;
		for (int i = 0; i < 4; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];
			if (nowR < 1 || nowR > N ||
				nowC < 1 || nowC > M) continue;
			int nowCost = cost + grid[nowR][nowC];

			if (dist[nowR][nowC] > nowCost) {
				dist[nowR][nowC] = nowCost;
				pq.push({ nowCost, nowR, nowC });
			}
			
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= M; j++) {
			grid[i][j] = input[j - 1] - '0';
			dist[i][j] = INF;
		}
	}

	cout << dijkstra() << "\n";
	return 0;
}