#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> parent;
vector <int> ranks;

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

	if (ranks[rootX] < ranks[rootY]) {
		parent[rootX] = rootY;
	}
	else if (ranks[rootX] > ranks[rootY]) {
		parent[rootY] = rootX;
	}
	else {
		parent[rootY] = rootX;
		ranks[rootX]++;
	}
}

bool connect(int x, int y) {
	return (find(x) == find(y));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M;
	
	parent.resize(N + 1);
	ranks.resize(N + 1, 0);

	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int input;
			cin >> input;
			if (input) {
				union_set(i, j);
			}
		}
	}
	int start;
	cin >> start;
	for (int i = 1; i < M; i++) {
		int end;
		cin >> end;
		if (!connect(start, end)) {
			cout << "NO";
			return 0;
		}
		start = end;
	}
	cout << "YES";
	return 0;
}