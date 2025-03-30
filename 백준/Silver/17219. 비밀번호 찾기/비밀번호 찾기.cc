#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	unordered_map<string, string> mp;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string site, pw;
		cin >> site >> pw;
		mp[site] = pw;
	}
	for (int i = 0; i < M; i++) {
		string site;
		cin >> site;
		cout << mp[site] << "\n";
	}
	return 0;
}