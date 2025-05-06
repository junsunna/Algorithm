#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N;
int grid[26][26];
int dr[4] = { 0, 0, -1, 1 };
int dc[4] = { 1, -1, 0, 0 };

int bfs(int row, int col) {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	grid[row][col] = 0;
	cnt++;
	while (!q.empty()) {
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];
			if (nowR < 1 || nowR > N ||
				nowC < 1 || nowC > N || grid[nowR][nowC] != 1) continue;
			q.push(make_pair(nowR, nowC));
			grid[nowR][nowC] = 0;
			cnt++;
		}
	}
	return cnt;

}

int main() {
	cin >> N;
	getchar();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			grid[i][j] = getchar() - 48;
		}
		getchar();
	}
	int cnt = 0;
	vector<int> v;
	while (1) {
		bool find = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (grid[i][j] == 1) {
					v.push_back(bfs(i, j));
					cnt++;
					find = true;
				}
			}
			if (find) break;
		}
		if (!find) break;
	}

	sort(v.begin(), v.end());
	cout << cnt << "\n";
	for (int p : v) {
		cout << p << "\n";
	}
	
	return 0;
}