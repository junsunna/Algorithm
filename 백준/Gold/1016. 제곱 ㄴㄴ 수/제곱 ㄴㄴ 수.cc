#include <iostream>
#include <vector>
using namespace std;

int initPrime() {
	long long minNum, maxNum;
	cin >> minNum >> maxNum;
	long long size = maxNum - minNum + 1;
	vector<bool> squares(size, true);
	for (long long i = 2; i * i <= maxNum; i++) {
		long long square = i * i;
		long long start = ((minNum + square - 1) / square) * square;
		for (long long j = start; j <= maxNum; j += square) {
			squares[j - minNum] = false;
		}
	}
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		if (squares[i]) cnt++;
	}
	return cnt;
	
}
int main() {

	cout << initPrime();
	
	return 0;
}