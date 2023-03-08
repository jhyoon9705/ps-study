#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, p, startP, endP;
int dist[1001];
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> adj[1001];

int main() {
	cin >> n >> m;
	fill(dist, dist + 1001, INF);
	for (int i = 0; i < m; i++) {
		cin >> s >> e >> p;
		adj[s].push_back({ p, e });
	}
	cin >> startP >> endP;
	dist[startP] = 0;
	pq.push({ 0, startP });
	while (pq.size()) {
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (dist[here] != here_dist) continue;
		for (auto there : adj[here]) {
			int _dist = there.first;
			int _there = there.second;
			if (dist[_there] > dist[here] + _dist) {
				dist[_there] = dist[here] + _dist;
				pq.push({ dist[_there], _there });
			}
		}
	}
	cout << dist[endP] << "\n";
	return 0;
}