#include <iostream>

int main() {
	int n, k, m;
	std::string pocket;
	std::string maxPocket;
	int count = 0;
	int maxCount = 0;

	std::cin >> n;
	
	while (n--) {
		int curCount = 0;
		std::cin >> pocket;
		std::cin >> k >> m;
		while (m > 0) {
			m = m - k;
			if (m >= 0) {
				m += 2;
				count++;
				curCount++;
			}
		}
		if (curCount > maxCount) {
			maxCount = curCount;
			maxPocket = pocket;
		}
	}
	std::cout << count << std::endl << maxPocket << std::endl;


}