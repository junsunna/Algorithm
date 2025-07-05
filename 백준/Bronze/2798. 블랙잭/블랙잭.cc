#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100];
int sum = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (arr[i] + arr[j] + arr[k] <= M) {
					sum = max(arr[i] + arr[j] + arr[k], sum);
				}
			}
		}
	}
	cout << sum;
	return 0;
}