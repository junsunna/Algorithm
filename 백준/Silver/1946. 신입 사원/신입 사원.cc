#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pair<int, int>> v;
		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a, b });
		}
		sort(v.begin(), v.end());

		int cnt = 1;
		bool flag = true;
		int minNum = v[0].second;
		for (int i = 1; i < N; i++) {
			flag = true;
			if (v[i].second < minNum) {
				minNum = v[i].second;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}