#include <iostream>
#include <queue>
using namespace std;

#define MAX 100001

int N, K;
int visited[MAX] = { 0 };  // 방문 여부 + 최단 거리 저장

int bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 1;  // 시작점 방문 처리 (거리 0 대신 1로 설정)

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		// 동생 위치 K에 도착하면 정답 반환
		if (cur == K) return visited[cur] - 1;

		int nextPos[] = { cur - 1, cur + 1, cur * 2 };
		for (int i = 0; i < 3; i++) {
			int next = nextPos[i];

			if (next >= 0 && next < MAX && visited[next] == 0) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}
	return -1;
}

int main() {
	cin >> N >> K;
	cout << bfs(N) << endl;

	return 0;
}