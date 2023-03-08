#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int dist[102];
int n, m, r, a, b, c, ret;
vector<pair<int, int>> adj[102];
int item[102];

int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	for (int i = 1; i <= n; i++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		fill(dist, dist + 102, INF);
		dist[i] = 0;
		pq.push({ 0, i });
		while (pq.size()) {
			int here = pq.top().second;
			int here_dist = pq.top().first;
			pq.pop();
			if (dist[here] != here_dist) continue;
			for (auto there : adj[here]) {
				int _there = there.second;
				int _dist = there.first;
				if (dist[_there] > dist[here] + _dist && dist[here] + _dist <= m) {
					dist[_there] = dist[here] + _dist;
					pq.push({ dist[_there], _there });
				}
			}
		}
		int itemNum = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[j] != INF) itemNum += item[j];
		}
		ret = max(ret, itemNum);
	}
	cout << ret << "\n";
	return 0;
}