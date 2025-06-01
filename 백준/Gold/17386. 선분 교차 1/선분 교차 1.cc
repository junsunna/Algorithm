#include <iostream>
using namespace std;

typedef struct {
	int x;
	int y;
} Point;

int ccw(Point a, Point b, Point c) {
	long long op = (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
	if (op > 0) return 1;
	if (op < 0) return -1;
	return 0;
}

bool isOverlapping(Point a, Point b, Point c, Point d) {
	if (max(a.x, b.x) < min(c.x, d.x)) return false;
	if (max(c.x, d.x) < min(a.x, b.x)) return false;
	if (max(a.y, b.y) < min(c.y, d.y)) return false;
	if (max(c.y, d.y) < min(a.y, b.y)) return false;

	return true;
}

bool isCross(Point a, Point b, Point c, Point d) {
	int ab_c = ccw(a, b, c);
	int ab_d = ccw(a, b, d);
	int cd_a = ccw(c, d, a);
	int cd_b = ccw(c, d, b);

	if (ab_c * ab_d == 0 && cd_a * cd_b == 0) {
		return isOverlapping(a, b, c, d);
	}
	return ab_c * ab_d <= 0 && cd_a * cd_b <= 0;
}

int main() {
	Point L1, L2, L3, L4;
	cin >> L1.x >> L1.y >> L2.x >> L2.y;
	cin >> L3.x >> L3.y >> L4.x >> L4.y;
	
	if (isCross(L1, L2, L3, L4)) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	return 0;
}