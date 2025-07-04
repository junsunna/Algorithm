#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <set>
#include <utility>
using namespace std;

int N, M, D;
int grid[15][15];
int kill = 0;

void move(int arr[15][15]) {
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) {
				if (i != N - 1) 
					arr[i + 1][j] = 1;
				arr[i][j] = 0;
			}
		}
	}
}

pair<int, int> find(int startR, int startC, int arr[15][15]) {
	bool visited[15][15] = { false };
	queue<tuple<int, int, int>> q;
	q.push({ startR, startC, 0 });
	visited[startR][startC] = true;

	int dr[3] = { 0, -1, 0 };
	int dc[3] = { -1, 0, 1 };

	while (!q.empty()) {
		int curR = get<0>(q.front());
		int curC = get<1>(q.front());
		int curD = get<2>(q.front());
		q.pop();

		if (curD > D) break;
		if (arr[curR][curC] == 1) return { curR, curC };

		for (int i = 0; i < 3; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];
			if (nowR < 0 || nowR >= N ||
				nowC < 0 || nowC >= M || visited[nowR][nowC] == 1) continue;
			visited[nowR][nowC] = true;
			q.push({ nowR, nowC, curD + 1 });
		}
	}
	return { -1, -1 };
}

void simulate(vector<int> archers, int arr[15][15]) {
	int kills = 0;
	for (int i = 0; i < N; i++) {
		set<pair<int, int>> targets;

		for (int archer : archers) {
			pair<int, int> findP = find(N, archer, arr);
			if (findP.first != -1) targets.insert(findP);
		}

		for (pair<int, int> target : targets) {
			if (arr[target.first][target.second] == 1) {
				arr[target.first][target.second] = 0;
				kills++;
			}
		}

		move(arr);
	}
	kill = max(kills, kill);
}

vector<int> aPos;
void position(int start, int aCnt) {
	if (aCnt == 3) {
		int temp[15][15];
		copy(&grid[0][0], &grid[0][0] + 15 * 15, &temp[0][0]);;
		simulate(aPos, temp);
		return;
	}
	for (int i = start; i < M; i++) {
		aPos.push_back(i);
		position(i + 1, aCnt + 1);
		aPos.pop_back();
	}
}

int main() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}
	position(0, 0);
	cout << kill;

	return 0;
}