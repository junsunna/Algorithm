#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> S;
	string order;
	int M, x;;
	cin >> M;
	while (M--) {
		cin >> order;
		if (order == "add") {
			cin >> x;
			sort(S.begin(), S.end());
			if (!binary_search(S.begin(), S.end(), x)) {
				S.push_back(x);
			}
		}
		else if (order == "remove") {
			cin >> x;
			sort(S.begin(), S.end());
			if (binary_search(S.begin(), S.end(), x)) {
				S.erase(lower_bound(S.begin(), S.end(), x));
			}
		}
		else if (order == "check") {
			cin >> x;
			sort(S.begin(), S.end());
			if (binary_search(S.begin(), S.end(), x)) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (order == "toggle") {
			cin >> x;
			sort(S.begin(), S.end());
			if (binary_search(S.begin(), S.end(), x)) {
				S.erase(lower_bound(S.begin(), S.end(), x));
			}
			else {
				S.push_back(x);
			}
		}
		else if (order == "all") {
			S.clear();
			for (int i = 1; i <= 20; i++) {
				S.push_back(i);
			}
		}
		else if (order == "empty") {
			S.clear();
		}
	}

	return 0;
}