#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	int N;
	cin >> N;
	vector<pair<int, int>> v;	
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	
	int rooms = 1;
	pq.push(v[0].second);
	for (int i = 1; i < N; i++) {
		if (pq.top() > v[i].first) {
			rooms++;
		}
		else {
			pq.pop();
		}
		pq.push(v[i].second);
	}
	cout << rooms;
	return 0;
}