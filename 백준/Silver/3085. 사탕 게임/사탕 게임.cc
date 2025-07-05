#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

char arr[50][50];
int N;

int getMax() {
	int res = 1;
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 1; j < N; j++) {
			if (arr[i][j] == arr[i][j - 1]) cnt++;
			else cnt = 1;
			res = max(res, cnt);
		}
		cnt = 1;
		for (int j = 1; j < N; j++) {
			if (arr[j][i] == arr[j - 1][i]) cnt++;
			else cnt = 1;
			res = max(res, cnt);
		}
	}

	return res;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			arr[i][j] = s[j];
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(arr[i][j], arr[i][j + 1]);
			answer = max(answer, getMax());
			swap(arr[i][j], arr[i][j + 1]);

			swap(arr[j][i], arr[j + 1][i]);
			answer = max(answer, getMax());
			swap(arr[j][i], arr[j + 1][i]);
		}
	}
	cout << answer;
	return 0;
}