#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int T, F;
vector<int> parent;
vector<int> sizes;
unordered_map<string, int> um;

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
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> F;
		parent.resize(F * 2);
		sizes.resize(F * 2, 1);
		for (int i = 0; i < F * 2; i++) {
			parent[i] = i;
		}
		string x, y;
		for (int i = 0; i < F*2; i+=2) {
			cin >> x >> y;
			if (um.find(x) == um.end())
				um[x] = i;
			if (um.find(y) == um.end())
				um[y] = i + 1;
			union_set(um[x], um[y]);
			cout << sizes[find(um[x])] << '\n';
		}	
		parent.clear();
		sizes.clear();
		um.clear();
	}
	return 0;
}