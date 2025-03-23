#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
bool visited[101];

int BFS() {
	int cnt = -1;
	queue<int> q;
	q.push(1);
	visited[1] = true;
	
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cnt++;

		for (int next : graph[node]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true; 
			}
		}
	}
	return cnt;
}

int main() {
	int C, N;
	cin >> C >> N;
	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	cout << BFS();

	return 0;
}