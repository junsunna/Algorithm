#include <iostream>
using namespace std;

int main() {
	int N;
	char result[100];
	string a, b;
	cin >> N >> a >> b;
	// rr ss pp rs rp sp
	for (int i = 0; i < N; i++) {
		if (a[i] == b[i]) {
			if (a[i] == 'R') {
				result[i] = 'P';
			}
			else if (a[i] == 'S') {
				result[i] = 'R';
			}
			else {
				result[i] = 'S';
			}
		}
		else if ((a[i] == 'R' && b[i] == 'S') || (a[i] == 'S' && b[i] == 'R')) {
			result[i] = 'R';
		}
		else if ((a[i] == 'R' && b[i] == 'P') || (a[i] == 'P' && b[i] == 'R')) {
			result[i] = 'P';
		}
		else {
			result[i] = 'S';
		}
	}
	result[N] = '\0';
	cout << result;
	return 0;
}