#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	int dp[1001] = { 1 };
	int arr[1001];
	for (int i = 0; i < N; i++) {
		int n;
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++) {
		int maxDP = 0;
		for (int j = 0; j < i; j++) {
			if (maxDP <= dp[j] && arr[i] > arr[j]) {
				maxDP = dp[j];
			}
		}
		dp[i] = maxDP + 1;
	}
	int max = dp[0];
	for (int i = 1; i < N; i++) {
		if (max < dp[i])
			max = dp[i];
	}
	cout << max;
}