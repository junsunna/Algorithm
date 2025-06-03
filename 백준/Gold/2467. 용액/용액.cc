#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> arr;

int binarySearchClosest(int left, int right, int target) {
	int best = arr[left];
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

pair<int, int> binarySearch() {
	int minSum = INT_MAX;
	pair<int, int> result;
	
	for (int i = 0; i < arr.size() - 1; i++) {
		int a = arr[i];
		int target = -a;
		int b = binarySearchClosest(i + 1, arr.size() - 1, target);

		int sum = abs(a + b);
		if (sum < minSum) {
			minSum = sum;
			result = { a, b };
		}
	}
	return result;
}

int main() {
	int N;
	cin >> N;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	pair<int, int> result = binarySearch();
	cout << result.first << " " << result.second;
	return 0;
}