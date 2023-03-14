#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int t, n, d, c, a, b, s, ans[10002], retA, retB;
vector<pair<int, int>> adj[10002]; 

int main() {
	cin >> t;
	while (t--) {
		retA = 0;
		retB = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		fill(ans, ans + 10002, INF);
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			adj[b].push_back({ s, a });
		}
		pq.push({ 0, c });
		ans[c] = 0;
		while (pq.size()) {
			int here = pq.top().second;
			int here_dist = pq.top().first;
			pq.pop();
			if (ans[here] != here_dist) continue;
			for (auto there : adj[here]) {
				int _dist = there.first;
				int _there = there.second;
				if (ans[_there] > _dist + ans[here]) {
					ans[_there] = _dist + ans[here];
					pq.push({ ans[_there], _there });
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (ans[i] != INF) {
				retA++;
				retB = max(retB, ans[i]);
			}
		}
		cout << retA << " " << retB << "\n";
		for (int i = 1; i <= n; i++) adj[i].clear();
	}	
	return 0;
}