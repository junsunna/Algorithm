#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		unordered_map<string, int> um;
		int N;
		cin >> N;
		for (int j = 0; j < N; j++) {
			string k, v;
			cin >> k >> v;
			um[v]++;
		}
		int arr[31];
		int size = 0;
		for (auto& p : um) {
			arr[size++] = ++p.second;
		}
		int result = 1;
		for (int j = 0; j < size; j++) {
			result *= arr[j];
		}
		cout << result - 1 << "\n";

	}

	return 0;
}