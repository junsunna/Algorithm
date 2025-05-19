#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9

int N, M, X;
vector<pair<int, int>> graph[1001];

vector<int> dijkstra(int start) {
	vector<int> dist(N+1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	
	while (!pq.empty()) {
		int curN = pq.top().second;
		int curD = pq.top().first;
		pq.pop();
		if (dist[curN] < curD) continue;

		for (auto& edge : graph[curN]) {
			int nowN = edge.first;
			int nowD = curD + edge.second;

			if (dist[nowN] > nowD) {
				dist[nowN] = nowD;
				pq.push({ nowD, nowN });
			}
		}
	}
	return dist;
}

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	vector<int> fromX = dijkstra(X);
	int result = 0;
	for (int i = 1; i <= N; i++) {
		vector<int> toX = dijkstra(i);
		result = max(result, toX[X] + fromX[i]);
	}
	cout << result;
	return 0;
}