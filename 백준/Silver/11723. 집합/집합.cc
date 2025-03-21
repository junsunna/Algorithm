#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> S(21);
	string order;
	int M, x;;
	cin >> M;
	while (M--) {
		cin >> order;
		if (order == "add") {
			cin >> x;
			S[x] = 1;
		}
		else if (order == "remove") {
			cin >> x;
			S[x] = 0;
		}
		else if (order == "check") {
			cin >> x;
			if (S[x]) {
				cout << "1\n";
			} else 
				cout << "0\n";
		}
		else if (order == "toggle") {
			cin >> x;
			if (S[x] == 0) S[x] = 1;
			else S[x] = 0;
		}
		else if (order == "all") {
			for (int i = 1; i <= 20; i++) {
				S[i] = 1;
			}
		}
		else if (order == "empty") {
			for (int i = 1; i <= 20; i++) {
				S[i] = 0;
			}
		}
	}

	return 0;
}