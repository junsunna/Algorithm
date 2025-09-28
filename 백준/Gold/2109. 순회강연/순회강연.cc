#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> lecture;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int N;
	cin >> N;
	int day, money;
	for (int i = 0; i < N; i++) {
		cin >> money >> day;
		lecture.push_back({ day, money });
	}
	sort(lecture.begin(), lecture.end(), [](const pair<int, int>& a,
		const pair<int, int>& b) {
			if (a.first == b.first) {
				return a.second > b.second;
			}
			else
				return a.first < b.first;
		});
	for (const auto& lec : lecture) {
		pq.push(lec.second);
		while (pq.size() > lec.first) {
			pq.pop();
		}
	}
	int sum = 0;
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;

	return 0;
}