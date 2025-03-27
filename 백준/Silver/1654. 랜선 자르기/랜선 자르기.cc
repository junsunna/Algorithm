#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;
vector<int> lines;

bool cutLine(int mid)
{
	long long cnt = 0;
	for (auto& line : lines) {
		cnt += line / mid;
	}
	return cnt >= N;
}

long long binarySearch(long long left, long long right) {
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (cutLine(mid)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return right;
}

int main() {
	cin >> K >> N;
	lines.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> lines[i];
	}
	sort(lines.begin(), lines.end());

	cout << binarySearch(1, lines[K - 1]);
	return 0;
}