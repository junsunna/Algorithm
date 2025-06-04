#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> cards;
vector<int> arr;
int N, M, K;

int find(int x) {
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void union_set(int x, int y) {
	parent[find(x)] = find(y);
}

int binary_search(int target) {
	int left = 0, right = M - 1;
	int res = M;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		
		if (cards[mid] > target) {
			res = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return res;
}

void turn() {

	for (int i = 0; i < K; i++) {
		int target = arr[i];
		int index = binary_search(target);
		int card_index = find(index);

		cout << cards[card_index] << '\n';
		union_set(card_index, card_index + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	cards.resize(M); // M만큼, 그리고 정렬
	parent.resize(M + 1);
	arr.resize(K);
	for (int i = 0; i < M; i++) {
		cin >> cards[i];
		parent[i] = i;
	}
	parent[M] = M;

	sort(cards.begin(), cards.end());

	for (int i = 0; i < K; i++) {
		cin >> arr[i];
	}
	turn();
	return 0;
}