#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> sizes;
int V, E;
vector<tuple<int, int, int>> graph;

int find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
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
	cin >> V >> E;
	parent.resize(V + 1);
	sizes.resize(V + 1);
	for (int i = 0; i <= V; i++) {
		parent[i] = i;
		sizes[i] = 1;
	}

	graph.resize(E);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[i] = { w, u, v };
	}
	sort(graph.begin(), graph.end());

	int cnt = 0;
	int weight = 0;
	for (tuple<int, int, int> edge : graph) {
		int x = get<1>(edge);
		int y = get<2>(edge);
		if (find(x) != find(y)) {
			union_set(x, y);
			weight += get<0>(edge);
			cnt++;
		}
		if (V - 1 == cnt) break;
	}
	cout << weight;
	return 0;
}