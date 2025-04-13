#include <iostream>
#include <queue>

using namespace std;

int N, M;
int res = 0;
char map[601][601]; // map 정보
int visited[601][601]; // 방문 여부 체크
pair<int, int> I_pos; // 도연이 위치

// 방향 배열(상하좌우)
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

// BFS (너비 우선 탐색) 알고리즘
void bfs()
{
	// 시작점을 queue에 저장 (시작점 : 도연이의 위치)
	queue<pair<int, int>> q;
	q.push(I_pos);
	visited[I_pos.first][I_pos.second] = 1; // 방문 여부 체크

	// 더 이상 갈 공간이 없을 떄 까지 무한 반복
	while (!q.empty())
	{
		// 현재 위치
		pair<int, int> cur = q.front();
		q.pop();

		// 방향 배열(dy[], dx[])을 통해 상하좌우 체크
		for (int i = 0; i < 4; i++)
		{
			// 이동할 위치
			pair<int, int> next = { cur.first + dy[i], cur.second + dx[i] };

			if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue; // map 밖을 벗어날 경우, 스킵
			if (map[next.first][next.second] == 'X') continue; // 벽일 경우, 스킵
			if (visited[next.first][next.second] == 1) continue; // 이미 방문한 위치일 경우, 스킵

			if (map[next.first][next.second] == 'P') res++; // 해당 위치에 사람이 있을 경우, 카운팅

			// 다음 위치 저장 및 방문 여부 체크
			q.push(next);
			visited[next.first][next.second] = 1;
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 캠퍼스 크기 입력
	cin >> N >> M;

	// 캠퍼스 정보 입력
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> map[y][x];

			// 도연이의 위치 저장
			if (map[y][x] == 'I')
			{
				I_pos.first = y;
				I_pos.second = x;
			}
		}
	}

	// BFS 알고리즘을 통해 도연이가 만날 수 있는 사람의 수 계산
	bfs();

	// 도연이가 만날 수 있는 사람의 수를 출력 
	// 아무도 만나지 못했을 경우, TT로 출력
	if (res == 0) cout << "TT";
	else cout << res;

	return 0;
}