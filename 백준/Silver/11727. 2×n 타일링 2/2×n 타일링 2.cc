#include <iostream>
using namespace std;
int N;

int tile(int N)
{
	int f0 = 0, f1 = 1, f2 = f0 + f1;
	for (int i = 2; i <= N; i++) {
		f2 = ((f0*2) + f1 % 10007);
		f0 = (f1 % 10007);
		f1 = (f2 % 10007);
	}
	return f2 % 10007;
}

int main() {
	cin >> N;
	cout << tile(N + 1);
	return 0;
}