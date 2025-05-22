#include <bits/stdc++.h> 
using namespace std;
const int INF = 2e9;
const int inf = 1e9;

vector<pair<int, int> > v[100001]; // node, cost
bool visited[100001];

int bfs(int i1, int i2) {
	int lo = 1;
	int hi = 1e9;
	int mid;
	int ret;
	
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		
		for (int i = 0; i < 100001; i++) visited[i] = false;
		
		queue<int> que;
		que.push(i1);
		visited[i1] = true;
		bool canMore = false;
		
		while (!que.empty()) {
			int node = que.front();
			que.pop();
			if (node == i2) {
				// mid 의 무게로 i1 - i2로 도착한 상황
				 canMore = true;
				 break;
			}
			
			for (int i = 0; i < v[node].size(); i++) {
				int next = v[node][i].first;
				int cost = v[node][i].second;
				if (visited[next]) continue;
				if (mid > cost) continue;
				visited[next] = true;
				que.push(next);
			}
		}
		if (canMore) {
			// 더 무겁게 가능? 
			lo = mid + 1;
			ret = mid;
		}
		else {
			// 더 가볍게 가능?
			hi = mid - 1; 
		}
	}
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// 양방향 그래프화 
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	int i1, i2;
	cin >> i1 >> i2;
	int ans = bfs(i1, i2);
	cout << ans;
	return 0;
}