#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> homes;

bool checkDistance(long long mid) {
	int cnt = 1;
	int lastPos = 0;
	for (int i = 1; i < N; i++) {
		if (homes[i] - homes[lastPos] >= mid) {
			lastPos = i;
			cnt++;
		}
	}
	return cnt >= C;
}

long long binarySearch(long long left, long long right)
{
	while (left <= right) {
		long long mid = (left + right) / 2;
		
		if (checkDistance(mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return right;
}

int main() {
	cin >> N >> C;
	homes.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> homes[i];
	}
	sort(homes.begin(), homes.end());

	cout << binarySearch(1, homes[N - 1] - homes[0]);

	return 0;
}