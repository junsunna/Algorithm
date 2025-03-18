#include <iostream>
using namespace std;

int main() {
	int num;
	int count = 0;
	cin >> num;
	while (num >= 5) {
		count += num / 5;
		num /= 5;
	}
	cout << count;
	return 0;
}