#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;
int N, E;
vector<pair<int, int>> graph[801];

vector<int> dijkstra(int start) {
	vector<int> dist(N + 1, INF);
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
				pq.push({ nowD, nowN });
				dist[nowN] = nowD;
			}
		}
	}

	return dist;
}

int main() {
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		graph[v].push_back({ u, w });
	}
	int second, last;
	cin >> second >> last;

	vector<int> fromRoot = dijkstra(1);
	vector<int> fromSecond = dijkstra(second);
	vector<int> fromLast = dijkstra(last);
	if (fromRoot[second] == INF ||
		fromRoot[last] == INF ||
		fromSecond[N] == INF ||
		fromSecond[last] == INF ||
		fromLast[second] == INF ||
		fromLast[N] == INF) {
		cout << -1;
		return 0;
	}
	int path1 = fromRoot[second] + fromSecond[last] + fromLast[N];
	int path2 = fromRoot[last] + fromLast[second] + fromSecond[N];
	
	int result = min(path1, path2);
	if (result == INF) cout << -1;
	else cout << result;
	return 0;
}