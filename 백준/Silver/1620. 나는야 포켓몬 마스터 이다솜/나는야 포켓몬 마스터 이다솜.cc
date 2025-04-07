#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isIntegerString(const string& str)
{
	if (str.empty()) return false;
	for (char c : str) {
		if (!isdigit(c)) return false;
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	unordered_map<int, string> m1;
	unordered_map<string, int> m2;
	for (int i = 1; i <= N; i++) {
		string name;
		cin >> name;
		m1[i] = name;
		m2[name] = i;
	}
	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;
		if (isIntegerString(input)) {
			cout << m1[stoi(input)] << "\n";
		}
		else {
			cout << m2[input] << "\n";
		}
		
	}

	return 0;
}