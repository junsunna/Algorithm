#include <iostream>
using namespace std;

int grid[5][8];
int top[5] = { 0 };

void rotate(int n, int d) {
	if (d == 1)
		top[n] = (top[n] + 7) % 8;
	else
		top[n] = (top[n] + 1) % 8;

}

bool isDifferent(int left, int right, int curTop[]) {
	int l_right = (curTop[left] + 2) % 8;
	int r_left = (curTop[right] + 6) % 8;
	return grid[left][l_right] != grid[right][r_left];
}

void move(int n, int d)
{
	int dir[5] = { 0 }; // 톱니바퀴 1~4의 회전 방향 저장
	dir[n] = d;

	int curTop[5];
	for (int i = 1; i <= 4; i++) curTop[i] = top[i];

	// 왼쪽으로 전파
	for (int i = n; i > 1; --i)
		if (isDifferent(i - 1, i, curTop)) 
			dir[i - 1] = -dir[i];
		else break;

	// 오른쪽으로 전파
	for (int i = n; i < 4; ++i)
		if (isDifferent(i, i + 1, curTop))
			dir[i + 1] = -dir[i];
		else break;

	// 회전 수행
	for (int i = 1; i <= 4; ++i)
		if (dir[i]) rotate(i, dir[i]);
}

int cal() {
	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		if (grid[i][top[i]] == 1) sum += (1 << (i - 1));
	}

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 1; i <= 4; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < 8; j++) {
			grid[i][j] = input[j] - '0';
		}
	}
	int T;
	cin >> T;
	while (T--) {
		int num, dir;
		cin >> num >> dir;
		move(num, dir);
	}
	cout << cal();
	return 0;
}