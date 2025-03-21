#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> v;
	int N, M, cnt = 0;
	vector<string> answer;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++) {
		string name;
		cin >> name;
		v.push_back(name);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N + M - 1; i++) {
		if (v[i] == v[i + 1]) {
			answer.push_back(v[i]);
			cnt++;
			i++;
		}
	}
	cout << cnt << "\n";
	for (auto& p : answer) {
		cout << p << "\n";
	}

	return 0;
}