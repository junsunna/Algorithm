#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> L1;
pair<int, int> L2;
int R, C;
char grid[1501][1501];
vector<int> parent;
vector<int> sizes;
queue<pair<int, int>> water;
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };

int idx(int r, int c) {
	return r * C + c;
}

int find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

bool union_set(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);
	if (rootX == rootY) return false;
	
	if (sizes[rootX] < sizes[rootY]) {
		parent[rootX] = rootY;
		sizes[rootY] += sizes[rootX];
	}
	else {
		parent[rootY] = rootX;
		sizes[rootX] += sizes[rootY];
	}
	return true;
}

void init_water() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (grid[i][j] != 'X') {
				water.push({ i,j });
				for (int d = 0; d < 4; d++) {
					int nowR = i + dr[d];
					int nowC = j + dc[d];
					if (nowR < 1 || nowC < 1 ||
						nowR > R || nowC > C) continue;
					if (grid[nowR][nowC] != 'X') {
						union_set(idx(i, j), idx(nowR, nowC));
					}
				}
			}
		}
	}
}

void day_water() {
	int day = 0;
	queue<pair<int, int>> next_water;

	while (true) {
		if (find(idx(L1.first, L1.second)) == find(idx(L2.first, L2.second))) {
			cout << day << '\n';
			break;
		}

		while (!water.empty()) {
			int curR = water.front().first;
			int curC = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nowR = curR + dr[i];
				int nowC = curC + dc[i];

				if (nowR < 1 || nowC < 1 ||
					nowR > R || nowC > C) continue;
				if (grid[nowR][nowC] == 'X') {
					grid[nowR][nowC] = '.';
					next_water.push({ nowR,nowC });

					for (int j = 0; j < 4; j++) {
						int nnowR = nowR + dr[j];
						int nnowC = nowC + dc[j];
						if (nnowR < 1 || nnowC < 1 ||
							nnowR > R || nnowC > C) continue;
						if (grid[nnowR][nnowC] != 'X') {
							union_set(idx(nowR, nowC), idx(nnowR, nnowC));
						}
					}
				}
			}
		}
		swap(water, next_water);
		day++;
	}
}

int main() {
	cin >> R >> C;
	bool l1 = false;
	parent.resize((R + 1) * (C + 1));
	sizes.resize((R + 1) * (C + 1), 1);
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= C; j++) {
			parent[idx(i, j)] = idx(i, j);
		}
	}

	for (int i = 1; i <= R; i++) {
		string input;
		cin >> input;
		for (int j = 1; j <= C; j++) {
			grid[i][j] = input[j-1];
			if (!l1 && grid[i][j] == 'L') {
				L1.first = i;
				L1.second = j;
				l1 = true;
			}
			else if (grid[i][j] == 'L') {
				L2.first = i;
				L2.second = j;
			}
		}
	}
	init_water();
	day_water();
	return 0;
}