#include <iostream>
using namespace std;

int main() {
	string input;
	cin >> input;
	int r1 = 0, r2 = 0;
	for (int i = 0; i < input.size(); i++) { 
		if (input.size() > i * 2) {
			r1 += input[i] - 'A';
		}
		else {
			r2 += input[i] - 'A';
		}
	}
	for (int i = 0; i < input.size(); i++) {
		if (input.size() > i * 2) {
			input[i] = 'A' + (r1 + input[i] - 'A') % 26;
		}
		else {
			input[i] = 'A' + (r2 + input[i] - 'A') % 26;
		}
	}
	for (int i = 0; i < input.size() / 2; i++) {
		input[i] = 'A' + (input[i] - 'A' + input[input.size() / 2 + i] - 'A') % 26;
	}
	for (int i = 0; i < input.size() / 2; i++) {
		cout << input[i];
	}
	return 0;
}