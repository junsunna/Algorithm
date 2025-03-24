#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, elements;

	cin >> N >> M;
	vector<int> v(N + 1, 0);
	vector<int> prefixSum(N + 1, 0);


	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		prefixSum[i] = prefixSum[i - 1] + v[i];
	}
	
	while (M--)
	{
		int i, j;
		cin >> i >> j;
		cout << prefixSum[j] - prefixSum[i - 1] << "\n";
	}


	return 0;
}