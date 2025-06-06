#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001];
int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	int result = dp[1];
	for (int i = 2; i <= N; i++) {
		int max = 0;
		for (int j = i-1; j > 0; j--) {
			if (arr[i] > arr[j] && max < dp[j]) {
				max = dp[j];
			}
		}
		dp[i] = arr[i] + max;
		if (result < dp[i])
			result = dp[i];
	}
	cout << result;
	
	return 0;
}