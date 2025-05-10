#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool visited[100001] = { 0 };
vector<int> selected[100001];
int arr[100001];
int N;
int cnt = 0;
queue<int> q;

void bfs(int start) {
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : selected[cur]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				arr[next] = cur;
			}

		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y;
		selected[x].push_back(y);
		selected[y].push_back(x);	
	}
	bfs(1);
	for (int i = 2; i <= N; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}