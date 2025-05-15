#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;

int N, M;
int d[50001];
vector<pair<int, int>> v[50001];

void dijkstra() {
    priority_queue <pair<int, int>> pq;

    d[1] = 0;
    pq.push({ 0,1 });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if (d[now] < cost) continue;

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i].first;
            int next_cost = cost + v[now][i].second;

            if (d[next] <= next_cost) continue;

            d[next] = next_cost;
            pq.push({ -next_cost, next });
        }
    }
}

void solution() {
    for (int i = 1; i <= N; i++) {
        d[i] = INF;
    }

    dijkstra();

    cout << d[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;

        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }

    solution();

    return 0;
}