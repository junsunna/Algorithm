#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), [&](const string& a, const string& b) {
		if (a.size() == b.size()) {
			int acnt = 0, bcnt = 0;

			for (char c : a) {
				if (isdigit(c)) {
					acnt += c - '0'; 
				}
			}
			for (char c : b) {
				if (isdigit(c)) {
					bcnt += c - '0';
				}
			}
			if (acnt == bcnt) {
				return a < b;
			}
			return acnt < bcnt;
		}
		return a.size() < b.size();
		});

	for (const string& str : v) {
		cout << str << endl;
	}

	return 0;
}