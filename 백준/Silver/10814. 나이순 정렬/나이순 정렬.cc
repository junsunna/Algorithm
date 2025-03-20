#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		return a.second.second < b.second.second;
	}
	return a.second.first < b.second.first;
}

int main(void) {
	int N;
	int age;
	string name;
	vector<pair<string, pair<int, int>>> v;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> age >> name;
		v.push_back(make_pair(name, make_pair(age, i)));
	}

	sort(v.begin(), v.end(), compare);

	for (auto p : v) {
		cout << p.second.first << " " << p.first << "\n";
	}

	return 0;
}