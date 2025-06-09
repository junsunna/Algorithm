#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;
int N;
int dp[501];

int main(int argc, char *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie();
	
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
			cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end());
	dp[1] = 1;
	
	int result = 1;
	for (int i = 2; i <= N; i++) {
		dp[i] = 1;
		for (int j = i-1; j > 0; j--) {
			if (arr[i - 1].second > arr[j - 1].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(result, dp[i]);
	}
	cout << N -result;
}