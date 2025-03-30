#include <iostream>
using namespace std;

int N, r, c, cnt = 0;

void cut(int x, int y, int size) {
	if (size == 1) {
		if (x == r && y == c) {
			cout << cnt << "\n";
		}
		cnt++;
		return;
	}

	int half = size / 2;
	if (r < x + half && c < y + half) {
		cut(x, y, half);
	}
	else if (r < x + half && c >= y + half) {
		cnt += half * half;
		cut(x, y + half, half);
	}
	else if (r >= x + half && c < y + half) {
		cnt += half * half * 2;
		cut(x + half, y, half);
	}
	else {
		cnt += half * half * 3;
		cut(x + half, y + half, half);
	}
}

int main() {
	cin >> N >> r >> c;
	int n = (1 << N);
	cut(0, 0, n);


	return 0;
}