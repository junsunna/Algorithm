#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int q = a * e - d * b;
	int x = (e * c - b * f) / q;
	int y = (a * f - d * c) / q;
	cout << x << ' ' << y << endl;

	return 0;
}