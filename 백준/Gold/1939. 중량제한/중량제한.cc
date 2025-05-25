#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
#define INF 1e9

int N, M;
vector<tuple<int, int>> graph[100000];

int dijkstra(int start, int end) {
	vector<int> dist(N + 1, 0);
	priority_queue<tuple<int, int>> pq;
	pq.push({ INF, start });
	/*for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}*/
	dist[start] = INF;

	while (!pq.empty()) {
		tuple<int, int> cur = pq.top();
		pq.pop();
		int curD = get<0>(cur);
		int curN = get<1>(cur);

		if (curN == end) {
			return curD;
		}
		for (auto & edge : graph[curN]) {
			int nowN = get<0>(edge);
			int nowD = get<1>(edge);
			int bottleneck = min(curD, nowD);
			if (bottleneck > dist[nowN]) {
				dist[nowN] = bottleneck;
				pq.push({ bottleneck, nowN });
			}
		}
	}
	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	int s, e;
	cin >> s >> e;
	cout << dijkstra(s, e);
	return 0;
}