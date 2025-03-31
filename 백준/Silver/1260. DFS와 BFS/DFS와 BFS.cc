#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, V;
queue<int> q;
vector<int> v[1001];
bool visitedD[1001] = { false };
bool visitedB[1001] = { false };

void BFS(int start) {
	q.push(start);
	visitedB[start] = true;
	cout << start << " ";
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		

		for (int next : v[cur]) {
			if (!visitedB[next]) {
				cout << next << " ";
				q.push(next);
				visitedB[next] = true;
			}

		}
	}
}

void DFS(int start) {
	visitedD[start] = true;
	cout << start << " ";

	sort(v[start].begin(), v[start].end());
	for (int next : v[start]) {
		if (!visitedD[next]) {
			DFS(next);
		}
	}
}

int main() {
	int x, y;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	DFS(V);
	cout << "\n";
	BFS(V);


	return 0;
}