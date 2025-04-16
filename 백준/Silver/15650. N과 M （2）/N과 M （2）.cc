#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
vector<bool> used;
void backtrack(int depth) {
	if (depth == M) {
		for (int n : v)
			cout << n << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (used[i] || (!v.empty() && v.back() > i)) continue;
		used[i] = true;
		v.push_back(i);
		backtrack(depth + 1);
		v.pop_back();
		used[i] = false;
	}

}

int main() {
	cin >> N >> M;
	used.resize(N + 1);
	for (int i = 1; i <= N; i++)
		used[i] = false;
	backtrack(0);

	return 0;
}