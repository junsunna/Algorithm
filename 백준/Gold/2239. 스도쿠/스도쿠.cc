#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> blanks;
int board[9][9];

void printBoard() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j];
		cout << '\n';
	}
}

bool isValid(int r, int c, int num) {
	for (int i = 0; i < 9; i++) 
		if (board[r][i] == num || board[i][c] == num) return false;
	
	int startRow = r / 3 * 3;
	int startCol = c / 3 * 3;
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

	int r = blanks[idx].first;
	int c = blanks[idx].second;
	for (int i = 1; i <= 9; i++) {
		if (isValid(r, c, i)) {
			board[r][c] = i;
			dfs(idx + 1);
			board[r][c] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < 9; j++) {
			board[i][j] = input[j] - '0';
			if (board[i][j] == 0)
				blanks.push_back({ i, j });
		}
	}
	dfs(0);
	return 0;

}