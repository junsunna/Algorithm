#include <iostream>
#include <vector>
using namespace std;

int G, P;
vector<int> parent;

int find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void union_set(int x, int y) {
	parent[find(x)] = find(y);
}

bool doking(int target) {
	int x = find(target);
	if (x == 0) return false;
	union_set(x, x - 1);
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> G >> P;
	parent.resize(G + 1);
	for (int i = 0; i <= G; i++) {
		parent[i] = i;
	}
	int cnt = 0;
	for (int i = 0; i < P; i++) {
		int input;
		cin >> input;
		if (doking(input)) {
			cnt++;
		}
		else break;
	}
	cout << cnt;

	
	return 0;
}