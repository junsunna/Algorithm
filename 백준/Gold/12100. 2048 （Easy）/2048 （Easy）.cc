#include <iostream>
#include <vector>
using namespace std;

int grid[21][21];
int N, ans = 0;


// 상하좌우 0, 1, 2, 3
void move(int dir) {
	int arr[21][21] = { 0 };

	for (int i = 0; i < N; i++) {
		vector<int> line;

		for (int j = 0; j < N; j++) {
			int val;
			switch (dir) {
			case 0: val = grid[j][i]; break;
			case 1: val = grid[N - 1 - j][i]; break;
			case 2: val = grid[i][j]; break;
			case 3: val = grid[i][N - 1 - j]; break;
			}
			if (val != 0) line.push_back(val);
		}
		vector<int> merged;
		for (int j = 0; j < line.size();) {
			if (j + 1 < line.size() && line[j] == line[j + 1]) {
				merged.push_back(line[j] * 2);
				j += 2;
			}
			else {
				merged.push_back(line[j]);
				j++;
			}
		}

		while (merged.size() < N) merged.push_back(0);

		for (int j = 0; j < N; j++) {
			int val = merged[j];
			switch (dir) {
			case 0: arr[j][i] = val; break;
			case 1: arr[N-1-j][i] = val; break;
			case 2: arr[i][j] = val; break;
			case 3: arr[i][N-1-j] = val; break;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			grid[i][j] = arr[i][j];
}

void dfs(int depth) {
	if (depth == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				ans = max(ans, grid[i][j]);
		return;
	}
	int backup[21][21];
	for (int d = 0; d < 4; d++) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				backup[i][j] = grid[i][j];

		move(d);
		dfs(depth + 1);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				grid[i][j] = backup[i][j];
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	dfs(0);
	cout << ans << '\n';
	return 0;
}