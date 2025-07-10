#include <iostream>
using namespace std;

int N, M;
int arr[101];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int max = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				int sum = arr[i] + arr[j] + arr[k];
				if (sum <= M && sum > max) {
					max = sum;
				}
			}
		}
	}
	cout << max;
	return 0;
}