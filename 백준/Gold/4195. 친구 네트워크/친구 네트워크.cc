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

		parent.clear();
		sizes.clear();
		um.clear();

		string x, y;
		int idx = 0;
		for (int i = 0; i < F; i++) {
			cin >> x >> y;

			if (um.find(x) == um.end()) {
				um[x] = idx;
				parent.push_back(idx);
				sizes.push_back(1);
				idx++;
			}
			if (um.find(y) == um.end()) {
				um[y] = idx;
				parent.push_back(idx);
				sizes.push_back(1);
				idx++;
			}

			union_set(um[x], um[y]);
			cout << sizes[find(um[x])] << '\n';
		}	
	}
	return 0;
}