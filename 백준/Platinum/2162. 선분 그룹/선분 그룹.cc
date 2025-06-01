#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef struct {
	int x;
	int y;
} Point;

int N;
vector<int> parent;
vector<int> sizes;
vector<pair<Point, Point>> list;


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


int countGroups() {
	set<int> roots;
	for (int i = 1; i <= N; i++) {
		roots.insert(find(i));
	}
	return roots.size();
}

int ccw(Point a, Point b, Point c) {
	long long op = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
	if (op > 0) return 1;
	if (op < 0) return -1;
	return 0;
}

bool isOverlapping(Point a, Point b, Point c, Point d) {
	if (max(a.x, b.x) < min(c.x, d.x)) return false;
	if (max(c.x, d.x) < min(a.x, b.x)) return false;
	if (max(a.y, b.y) < min(c.y, d.y)) return false;
	if (max(c.y, d.y) < min(a.y, b.y)) return false;

	return true;
}

bool isCross(Point a, Point b, Point c, Point d) {
	int ab_c = ccw(a, b, c);
	int ab_d = ccw(a, b, d);
	int cd_a = ccw(c, d, a);
	int cd_b = ccw(c, d, b);

	if (ab_c * ab_d == 0 && cd_a * cd_b == 0) {
		return isOverlapping(a, b, c, d);
	}
	return ab_c * ab_d <= 0 && cd_a * cd_b <= 0;
}

int main() {
	cin >> N;
	parent.resize(N + 1);
	sizes.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		sizes[i] = 1;
	}
	for (int i = 0; i < N; i++) {
		Point L1, L2;
		cin >> L1.x >> L1.y >> L2.x >> L2.y;
		list.push_back({ L1, L2 });
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (isCross(list[i].first, list[i].second, list[j].first, list[j].second)) {
				union_set(i + 1, j + 1);
			}
		}
	}

	int max_size = 0;
	for (int i = 1; i <= N; i++) {
		if (parent[i] == i && sizes[i] > max_size) {
			max_size = sizes[i];
		}
	}
	cout << countGroups() << endl;
	cout << max_size;
	
	return 0;
}