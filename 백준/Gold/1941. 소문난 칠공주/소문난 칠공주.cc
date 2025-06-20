#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char board[5][5];
bool used[5][5];
int result = 0;
vector<pair<int, int>> v;

bool bfs(vector<pair<int, int>> group) {
	queue<pair<int, int>> q;
	bool visited[5][5] = { false };
	q.push(group[0]);
	visited[group[0].first][group[0].second] = true;
	int cnt = 1;

	while (!q.empty()) {
		int dr[4] = { 0, 0, 1, -1 };
		int dc[4] = { 1, -1, 0, 0 };
		int curR = q.front().first;
		int curC = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nowR = curR + dr[i];
			int nowC = curC + dc[i];
			for (pair<int, int> gr : group) {
				if (gr.first == nowR && gr.second == nowC && !visited[nowR][nowC]) {
					visited[nowR][nowC] = true;
					q.push({ nowR, nowC });
					cnt++;
					break;
				}
			}
		}
	}
	return cnt == 7;
}

void backtrack(int idx, int S, int Y) {
	if (Y >= 4) return;
	if (v.size() == 7) {
		if (bfs(v))
			result++;
		return;
	}
	
	for (int i = idx; i < 25; i++) {
		int r = i / 5;
		int c = i % 5;
		if (used[r][c]) continue;

		used[r][c] = true;
		v.push_back({ r, c });
		if (board[r][c] == 'S')
			backtrack(i + 1, S + 1, Y);
		else
			backtrack(i + 1, S, Y + 1);
		used[r][c] = false;
		v.pop_back();
	}

}

int main() {
	for (int i = 0; i < 5; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < 5; j++) 
			board[i][j] = input[j];
	}
	backtrack(0, 0, 0);
	cout << result << '\n';
	return 0;
}