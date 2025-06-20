#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> blanks;
int board[9][9];

void printBoard() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}

bool isValid(int row, int col, int num) {
	for (int i = 0; i < 9; i++)
		if (board[row][i] == num) return false;
	for (int i = 0; i < 9; i++)
		if (board[i][col] == num) return false;

	int startRow = row / 3 * 3;
	int startCol = col / 3 * 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[startRow + i][startCol + j] == num) return false;
	return true;
}

void dfs(int idx) {
	if (idx == blanks.size()) {
		printBoard();
		exit(0);
	}
	int x = blanks[idx].first;
	int y = blanks[idx].second;

	for (int i = 1; i <= 9; i++) {
		if (isValid(x, y, i)) {
			board[x][y] = i;
			dfs(idx + 1);
			board[x][y] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) blanks.push_back({i, j});
		}
	}
	dfs(0);
}