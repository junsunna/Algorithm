#include <iostream>
#include <stack>
using namespace std;

int N;
int result = 0;
bool col[15], diag1[30], diag2[30];

void dfs(int row) {
	if (row == N) {
		result++;
		return;
	}

	for (int c = 0; c < N; c++) {
		// 해당 열에 놓인 퀸이 있는가?
		// 대각선 왼쪽 오른쪽에 놓인 퀸이 있는가?
		if (col[c] || diag1[row - c + N - 1] || diag2[row + c]) continue;

		// 퀸을 놓아보자
		col[c] = diag1[row - c + N - 1] = diag2[row + c] = true;

		// 다음 행 넘어가자 총 N개의 퀸을 놔야되니까
		dfs(row + 1); 

		// 백트래킹, 상태 초기화
		col[c] = diag1[row - c + N - 1] = diag2[row + c] = false;
	}
}

int main() {
	cin >> N;
	dfs(0);
	cout << result << "\n";
}