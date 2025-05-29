#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> parent;
vector<int> ranks;
vector<vector<int>> parties;
vector<int> truth;

int find(int x) {
	if (parent[x] != x)
		parent[x] = find(parent[x]);
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	
	parent.resize(N + 1);
	ranks.resize(N + 1, 0);
	parties.resize(M);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	int a;
	cin >> a;

	for (int i = 0; i < a; i++) {
		int input;
		cin >> input;
		truth.push_back(input);
	}
	for (int i = 0; i < M; i++) {
		int count;
		cin >> count;
		parties[i].resize(count);

		for (int j = 0; j < count; j++) {
			cin >> parties[i][j];
		}
		for (int j = 1; j < count; j++) {
			union_set(parties[i][0], parties[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool result = true;
		for (int person : parties[i]) {
			for (int tr : truth) {
				if (find(person) == find(tr)) {
					result = false;
					break;
				}
			}
			if (!result) break;
		}
		if (result) cnt++;
	}
	printf("%d", cnt);

	return 0;
}