#include <iostream>
#include <string>
#include <stack>
using namespace std;

string expression;

int main() {
	cin >> expression;
	stack<int> s;
	int size = expression.size();
	int lastIndex = 0;
	int num;
	int sum = 0;
	int result = 0;
	int toggle = 0;
	while (lastIndex < size) {
		int len = 0;
		
		for (int i = lastIndex; i < size; i++) {
			if (expression[i] >= '0') {
				len++;
			}
			else break;
		}
		num = stoi(expression.substr(lastIndex, len));
		lastIndex += len;
		if (lastIndex == size) {
			if (expression[lastIndex - len - 1] == '-') {
				result -= num;
			}
			else {
				if (toggle == 1) {
					result -= num;
				}
				else {
					result += num;
				}
			}
			continue;
		}
		if (lastIndex - len - 1 >= 0 && expression[lastIndex - len - 1] == '+') {
			if (toggle == 1) {
				result -= num;
			}
			else {
				result += num;
			}
		}
		else if (lastIndex - len - 1 >= 0 && expression[lastIndex - len - 1] == '-') {
			result -= num;
			if (toggle == 0)
				toggle ^= 1;
		}
		else result += num;
		lastIndex++;
	}

	result += sum;
	std::cout << result;
	return 0;
}