#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int T, V, E, W;
	cin >> T;
	while (T--) {
		cin >> V >> E;
		vector<vector<int>> graph(V + 1);
		vector<int> indegree(V + 1, 0);
		vector<int> time(V + 1, 0);
		vector<int> dp(V + 1, 0);

		for (int i = 1; i <= V; i++) {
			cin >> time[i];
		}
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			indegree[v]++;
		}
		cin >> W;

		queue<int> q;

		for (int i = 1; i <= V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				dp[i] = time[i];
			}
		}


		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			//if (cur == W) break;

			for (int next : graph[cur]) {
				indegree[next]--;

				dp[next] = max(dp[next], dp[cur] + time[next]);
				
				if (indegree[next] == 0) {
					q.push(next);
				}
			}
		}
		cout << dp[W] << '\n';
	}
	return 0;
}