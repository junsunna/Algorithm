#include <iostream>
using namespace std;

int grid[1001][1001] = { 0 };
int arr[101] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = a; j < a + c; j++) {
			for (int k = b; k < b + d; k++) {
				if (grid[j][k] == 0) {
					grid[j][k] = i;
					arr[i]++;
				}
				else {
					arr[grid[j][k]]--;
					grid[j][k] = i;
					arr[i]++;
				}
				
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}