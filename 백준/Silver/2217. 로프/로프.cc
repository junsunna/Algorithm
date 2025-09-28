#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (max < arr[i] * (N - i)) {
			max = arr[i] * (N - i);
		}
	}
	cout << max;
	return 0;
}