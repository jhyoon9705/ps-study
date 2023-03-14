#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, from, to, val, ans[202], ret[202][202];
vector<pair<int, int>> adj[202];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> val;
		adj[from].push_back({ val, to });
		adj[to].push_back({ val, from });
	}
	for (int i = 1; i <= n; i++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		fill(ans, ans + 202, INF);
		ans[i] = 0;
		pq.push({ 0, i });
		while (pq.size()) {
			int here = pq.top().second;
			int here_dist = pq.top().first;
			pq.pop();
			if (ans[here] != here_dist) continue;
			for (auto there : adj[here]) {
				int _dist = there.first;
				int _there = there.second;
				if (ans[_there] > ans[here] + _dist) {
					if (ret[i][here] == 0) ret[i][_there] = _there;
					else ret[i][_there] = ret[i][here];
					ans[_there] = ans[here] + _dist;
					pq.push({ ans[_there], _there });
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "-" << " ";
			else cout << ret[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}