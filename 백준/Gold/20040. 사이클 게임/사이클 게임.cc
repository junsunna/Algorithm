#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> ranks;
vector<int> list;
int N, M;

int find(int x) {
	if (parent[x] != x) 
		parent[x] = find(parent[x]);
	
	return parent[x];
}

bool union_set(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);

	if (rootX == rootY) return false;
	if (ranks[rootX] < ranks[rootY]) 
		parent[rootX] = rootY;
	else if (ranks[rootX] > ranks[rootY]) 
		parent[rootY] = rootX;
	else {
		parent[rootY] = rootX;
		ranks[rootX]++;
	}
	return true;
}

int main() {
	cin >> N >> M;
	parent.resize(N);
	ranks.resize(N, 0);
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	int count = 0;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		if (!union_set(x, y)) {
			cout << i + 1 << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';

	return 0;
}