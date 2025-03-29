#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int N, M;
vector<int> graph[1001];
bool visited[1001] = { false };

void BFS(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int next : graph[node]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	int u, v, cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			BFS(i);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}