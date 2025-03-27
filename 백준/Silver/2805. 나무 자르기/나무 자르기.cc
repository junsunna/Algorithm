#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> trees;

long long getWood(int height) {
	long long total = 0;
	for (int tree : trees) {
		if (tree > height) total += (tree - height);
	}
	return total;
}

int binarySearch(int left, int right) { 
	int result = 0;

	while (left <= right) {
		int mid = (left + right) / 2; // 중간 인덱스 설정
		// left는 증가 right는 감소하는 방식으로 while문 반복

		if (getWood(mid) >= M) { // 조건은 만족, 최대높이인지는 모름
			result = mid; // 만족하는 최대 높이값을 갱신
			left = mid + 1; // 높이를 높혀서 재시도
		}
		else {
			right = mid - 1; // 1. 처음부터 중간값이 너무 높는 경우
			// 2. 위의 조건 만족하여 중간값이 높아진 경우
		}
	}
	return result;
}

int main() {
	cin >> N >> M;
	trees.resize(N);
	for (int i = 0; i < N; i++) cin >> trees[i];

	sort(trees.begin(), trees.end());

	cout << binarySearch(0, trees[N - 1]) << endl;
	return 0;
}