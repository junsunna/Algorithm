#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrPlus[1000001] = { 0 };
int arrMinus[1000001] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, input;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input >= 0) {
			arrPlus[input] = 1;
		}
		else {
			arrMinus[-input] = 1;
		}
		
	}
	
	for (int i = 1000000; i > 0; i--) {
		if (arrMinus[i]) {
			cout << -i << '\n';
		}
	}

	for (int i = 0; i < 1000001; i++) {
		if (arrPlus[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}