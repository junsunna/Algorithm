#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main(void) {
	int N;
	int x, y;
	vector<pair<int, int>> v;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), compare);

	for (auto p : v) {
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
}