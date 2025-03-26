#include <iostream>
#include <utility>
using namespace std;

int N;
int grid[129][129];
int blue = 0, white = 0;
void cut(pair<int, int> s, pair<int, int> e) {
	if (s.first == e.first && s.second == e.second) {
		if (grid[s.first][s.second]) {
			blue++;
		}
		else {
			white++;
		}
		return;
	}
	int toggle = 0;
	for (int i = s.first; i <= e.first; i++) {
		for (int j = s.second; j <= e.second; j++) {
			if (grid[i][j] != grid[s.first][s.second]) {
				toggle = 1;
				break;
			}
		}
		if (toggle) break;
	}
	if (toggle) {
		int rcoef = (e.second - s.second + 1) / 2;
		int ccoef = (e.first - s.first + 1) / 2;
		cut(make_pair(s.first, s.second), make_pair(s.first + rcoef - 1, s.second + ccoef -1));
		cut(make_pair(s.first, s.second + ccoef), make_pair(s.first + rcoef - 1,	e.second));
		cut(make_pair(s.first + rcoef, s.second), make_pair(e.first, s.second + ccoef - 1));
		cut(make_pair(s.first + rcoef, s.second +ccoef), make_pair(e.first, e.second));
	}
	else {
		if (grid[s.first][s.second]) {
			blue++;
		}
		else {
			white++;
		}
		return;
	}
}

int main() {
	int n;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> n;
			grid[i][j] = n;
		}
	}
	pair<int, int> s = make_pair(1, 1);
	pair<int, int> e = make_pair(N, N);
	cut(s, e);
	cout << white << "\n" << blue;

	return 0;
}