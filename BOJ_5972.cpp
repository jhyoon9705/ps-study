#include <bits/stdc++.h>
using namespace std;

int dist[500002];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> adj[500002];
int n, m, a_i, b_i, c_i;
const int INF = 987654321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a_i >> b_i >> c_i;
		adj[a_i].push_back({ c_i, b_i });
		adj[b_i].push_back({ c_i, a_i });
	}
	fill(dist, dist + 500002, INF);
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (pq.size()) {
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (here_dist != dist[here]) continue;
		for (auto there : adj[here]) {
			int _there = there.second;
			int _dist = there.first;
			if (dist[_there] > dist[here] + _dist) {
				dist[_there] = dist[here] + _dist;
				pq.push({ dist[_there], _there });
			}
		}
	}
	cout << dist[n] << '\n';
	return 0;
}