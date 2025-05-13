#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
int N, M;

vector<pair<int, int>> graph[1001];
vector<int> dist(1001, INF);

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
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	int start, end;
	cin >> start >> end;
	dijkstra(start);
	cout << dist[end];
	return 0;
}