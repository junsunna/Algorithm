#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int N, weight, height;
	unordered_map<int, pair<int, int>> umap;
	int list[51] = {};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weight >> height;
		umap.emplace(i, make_pair(weight, height));
	}
	for (auto it1 = umap.begin(); it1 != umap.end(); ++it1) {
		list[it1->first] = 1;
		for (auto it2 = umap.begin(); it2 != umap.end(); ++it2) {
			if (it1->first != it2->first) {
				if (it1->second.first < it2->second.first &&
					it1->second.second < it2->second.second) {
					list[it1->first] += 1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << list[i] << " ";
	}
	return 0;
}