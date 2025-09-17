#include <iostream>
using namespace std;

int N, M, K;
int A[100][100];
int B[100][100];
int C[100][100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int sum = 0;
			for (int k = 0; k < M; k++) {
				 sum += A[i][k] * B[k][j];
			}
			C[i][j] = sum;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << C[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}