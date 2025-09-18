#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<pair<int, int>> selected_chickens;
int result = INT_MAX;

void carRange()
{
	int currentDistance = 0;

	for (const auto& h : houses) {
		int minDistance = INT_MAX;

		for (const auto& c : selected_chickens) {
			int dist = abs(h.first - c.first) + abs(h.second - c.second);
			minDistance = min(minDistance, dist);
		}
		currentDistance += minDistance;
	}
	result = min(result, currentDistance);
}

void backtracking(int depth, int start) {
	if (depth == M) {
		carRange();
		return;
	}
	for (int i = start; i < chickens.size(); i++) {
		selected_chickens.push_back(chickens[i]);
		backtracking(depth + 1, i + 1);
		selected_chickens.pop_back();
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cell;
			cin >> cell;
			if (cell == 1) {
				houses.push_back({ i, j });
			}
			else if (cell == 2) {
				chickens.push_back({ i, j });
			}
		}
	}
	
	backtracking(0, 0);
	cout << result << '\n';
	

	return 0;
}