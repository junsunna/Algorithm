#include <iostream>
using namespace std;

bool checkNum(int number)
{
	int collectIndex = 0;
	while (number > 0)
	{
		if (number % 10 == 6) {
			number /= 10;
			collectIndex++;
			if (collectIndex == 3) {
				return true;
			}
		}
		else {
			number /= 10;
			collectIndex = 0;
		}
	}
	return false;
}

int main(void) {
	int n, num = 0;
	int index = 666;
	cin >> n;
	while (true)
	{
		if (checkNum(index)) {
			num++;
		}
		if (n == num) {
			break;
		}
		index++;
	}
	cout << index;

	return 0;
}