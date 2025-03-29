#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int N;
	vector<pair<int, int>> v;
	int index = 0;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v[i] = make_pair(i, x);
	}
	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b){
		return a.second < b.second;
		});

	int last = v[0].second;
	v[0].second = 0;
	for (int i = 1; i < N; i++) {
		if (v[i].second == last) {
			v[i].second = v[i - 1].second;
		}
		else {
			last = v[i].second;
			v[i].second = ++index;
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].second << " ";
	}

	return 0;
}