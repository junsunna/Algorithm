#include <iostream>
#include <vector>
using namespace std;

int T, V, E;
vector<int> graph[20001];
bool visited[20001] = { 0 };
bool color[20001];
bool result = true;

void dfs(int start, bool toggle) {
	if (!result) return;

	visited[start] = true;
	color[start] = toggle;

	for (int next : graph[start]) {
		if (!visited[next]) {
			dfs(next, !toggle);
		}
		else if (visited[next]) {
			if (color[next] == color[start] && result == true) {
				cout << "NO" << endl;
				result = false;
				return;
			}
		}
	}
	
}

int main() {
	cin >> T;
	while (T--) {
		result = true;
		cin >> V >> E;
		for (int i = 1; i <= V; i++) {
			visited[i] = false;
			color[i] = false;
			graph[i].clear();
		}
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (int i = 1; i <= V; i++) {
			if (!visited[i]) {
				dfs(i, 1);
			}
		}
		if (result) cout << "YES" << endl;
	}
	return 0;
}