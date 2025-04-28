#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int N, M;
int arr[8];
vector<int> v;
map<vector<int>, int> m;
void backtracking(int depth) {
	if (depth == M) {
		m.emplace(v, 1);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!v.empty() && v.back() > arr[i]) continue;
		v.push_back(arr[i]);
		backtracking(depth + 1);
		v.pop_back();
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	backtracking(0);
	for (auto &p : m) {
		for (int q : p.first) {
			cout << q << " ";
		}
		cout << "\n";
	}
	return 0;
}