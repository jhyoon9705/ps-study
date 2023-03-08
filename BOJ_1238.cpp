#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N, M, X, a, b, c, ret;
int dist[1002], ans[1002];
vector<pair<int, int>> adj[1002];

int main() {
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}
	fill(ans, ans + 1002, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, X });
	ans[X] = 0;
	while (pq.size()) {
		int here = pq.top().second;
		int here_dist = pq.top().first;
		pq.pop();
		if (ans[here] != here_dist) continue;
		for (pair<int, int> there : adj[here]) {
			int _dist = there.first;
			int _there = there.second;
			if (ans[_there] > _dist + ans[here]) {
				ans[_there] = _dist + ans[here];
				pq.push({ ans[_there], _there });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		fill(dist, dist + 1002, INF);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, i });
		dist[i] = 0;
		while (pq.size()) {
			int here = pq.top().second;
			int here_dist = pq.top().first;
			pq.pop();
			if (dist[here] != here_dist) continue;
			for (auto there : adj[here]) {
				int _dist = there.first;
				int _there = there.second;
				if (dist[_there] > _dist + dist[here]) {
					dist[_there] = _dist + dist[here];
					pq.push({ dist[_there], _there });
				}
			}
		}
		ans[i] += dist[X];
		ret = max(ret, ans[i]);
	}
	cout << ret << "\n";
	return 0;
}