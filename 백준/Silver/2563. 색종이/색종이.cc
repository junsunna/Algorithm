#include <iostream>
using namespace std;

int grid[101][101] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N;
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a; j < a + 10; j++) {
			for (int k = b; k < b + 10; k++) {
				if (grid[j][k] == 0) {
					grid[j][k] = 1;
					cnt++;
				}
				
			}
		}
	}
	cout << cnt;

	return 0;
}