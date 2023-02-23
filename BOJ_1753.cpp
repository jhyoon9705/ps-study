// Dijkstra's algorithm
#include <bits/stdc++.h>
using namespace std;

int V, E, K, u, v, w;
int dist[20001];
bool visited[20001];
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> adj[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E >> K;
	fill(dist, dist + 20001, INF);
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}
	pq.push({ 0, K });
	dist[K] = 0;
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
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
	return 0;
}