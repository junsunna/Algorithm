#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <climits>
using namespace std;

int N;
vector<long long> arr;

int binary(int left, long long target) {
	int right = N - 1;
	long long best = arr[left];
	
	while (left <= right) {
		int mid = (left + right) / 2;

		if (abs(arr[mid] - target) < abs(best - target)) {
			best = arr[mid];
		}

		if (arr[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	return best;
}

tuple<long long, long long, long long> binarySearch() {
	long long minSum = LONG_MAX;
	tuple<long long, long long, long long> result;

	for (int i = 0; i < N - 1; i++) {
		int a = arr[i];
		for (int j = i + 1; j < N - 1; j++) {
			long long b = arr[j];
			long long target = -(a + b);
			long long c = binary(j + 1, target);

			long long sum = abs(a + b + c);
			if (sum < minSum) {
				minSum = sum;
				result = make_tuple(a, b, c);
			}
		}
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	tuple<long long, long long, long long> result = binarySearch();
	cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result);
	return 0;
}