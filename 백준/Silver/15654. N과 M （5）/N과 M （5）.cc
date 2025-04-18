#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<int> v;
vector<bool> used;

void backtracking(int depth)
{
	if (depth >= M) {
		for (int n : v) {
			cout << n << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (used[i]) continue;
		used[i] = true;
		v.push_back(arr[i]);
		backtracking(depth + 1);
		used[i] = false;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	arr.resize(N + 1);
	used.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		used[i] = false;
	}
	
	sort(arr.begin(), arr.end());
	backtracking(0);

	return 0;
}