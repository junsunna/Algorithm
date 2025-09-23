#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v1;
vector<int> v2;
vector<int> v3;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		v1.push_back(input);
	}
	
	for (const auto& a : v1) {
		if (a <= 0) {
			v3.push_back(a);
		}
		else {
			v2.push_back(a);
		}
	}
	sort(v2.rbegin(), v2.rend());
	sort(v3.begin(), v3.end());

	long long sum = 0;

	for (int i = 0; i < v2.size(); i += 2) {
		if (i + 1 == v2.size()) {
			sum += v2[i];
			break;
		}
		int a = v2[i];
		int b = v2[i + 1];

		if (a == 1 || b == 1) {
			sum += a + b;
		}
		else
			sum += (long long)a * b;
	}

	for (int i = 0; i < v3.size(); i += 2) {
		if (i + 1 == v3.size()) {
			sum += v3[i];
			break;
		} 
		int a = v3[i];
		int b = v3[i + 1];

		sum += (long long)a * b;
	}
	cout << sum;
	return 0;
}