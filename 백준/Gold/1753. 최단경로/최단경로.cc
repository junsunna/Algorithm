#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;
int V, E;
vector<pair<int, int>> graph[20001];
vector<int> dist(20001, INF);
void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

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
}

int main() {
	cin >> V >> E;
	int start;
	cin >> start;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	dijkstra(start);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	
	return 0;
}