#include <iostream>
#include <string>
int main() {
	std::string s;
	std::cin >> s;
	int size = s.size();
	int lastIndex = 0;
	int num, sum = 0, result = 0;
	bool toggle = 0;
	while (lastIndex < size) {
		int len = 0;
		for (int i = lastIndex; i < size; i++) 
			if (s[i] >= '0' && s[i] <= '9') 
				len++;
			else break;
		num = std::stoi(s.substr(lastIndex, len));
		if (!toggle && lastIndex - 1 > 0 && s[lastIndex - 1] == '-') toggle = 1;
		if (toggle == 0) 
			result += num;
		else 
			sum += num;
		lastIndex += len + 1;
	}
	result -= sum;
	std::cout << result;
	return 0;
}