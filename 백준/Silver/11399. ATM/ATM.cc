#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, P, sum = 0;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> P;
		v.push_back(P);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N - 1; i++) {
		v[i + 1] = v[i + 1] + v[i];
		sum += v[i];
	}
	sum += v[N - 1];
	cout << sum;

	return 0;
}