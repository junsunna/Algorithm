#include <iostream>
using namespace std;

int N, M;
int arr[301][301];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	int K;
	cin >> K;
	while (K--) {
		int x1, y1, x2, y2;
		int sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i <= x2; i++) {
			for (int j = y1; j <= y2; j++) {
				sum += arr[i][j];
			}
		}
		cout << sum << '\n';
	}
	return 0;
}