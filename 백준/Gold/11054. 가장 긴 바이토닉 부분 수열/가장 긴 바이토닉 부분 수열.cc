#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int N;
int dp[1001] = { 0 };

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		int maxDP = 0;
		for (int j = 1; j < i; j++) {
			if (maxDP <= dp[j] && arr[i] > arr[j]) {
				maxDP = dp[j];
			}
		}
		dp[i] = maxDP + 1;
	}
	int AP[1001] = { 0 };
	AP[N] = 1;
	for (int i = N - 1; i >= 1; i--) {
		int maxDP = 0;
		for (int j = N; j > i; j--) {
			if (maxDP <= AP[j] && arr[i] > arr[j]) {
				maxDP = AP[j];
			}
		}
		AP[i] = maxDP + 1;
	}
	int max = dp[1] + AP[1] - 1;
	for (int i = 2; i <= N; i++) {
		if (max < dp[i] + AP[i] - 1)
			max = dp[i] + AP[i] - 1;
	}
	cout << max;

	return 0;
}