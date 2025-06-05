#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

vector<int> parent;
vector<int> sizes;
vector<tuple<int, int, int>> graph;
int N, M;

int find(int x) {
	if (parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}

void union_set(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);
	if (rootX == rootY) return;
	
	if (sizes[rootX] < sizes[rootY]) {
		parent[rootX] = rootY;
		sizes[rootY] += sizes[rootX];
	}
	else {
		parent[rootY] = rootX;
		sizes[rootX] += sizes[rootY];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> N >> M;
	parent.resize(N + 1);
	sizes.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sizes[i] = i;
	}
	
	graph.resize(M);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[i] = { w, u, v };
	}
	sort(graph.begin(), graph.end());
	
	int cnt = 0, weight = 0;
	for (tuple<int, int, int> edge : graph) {
		if (cnt >= N - 2) break;
		int w = get<0>(edge);
		int x = get<1>(edge);
		int y = get<2>(edge);
		if (find(x) != find(y)) {
			union_set(x, y);
			cnt++;
			weight += w;
		}
		
	}
	cout << weight;


	return 0;
}