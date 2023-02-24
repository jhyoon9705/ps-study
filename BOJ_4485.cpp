#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n;
int dist[126][126], arr[126][126];
vector<pair<int, int>> adj[16000];
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

void solve() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ arr[0][0], {0, 0} });
	dist[0][0] = arr[0][0];
	while (pq.size()) {
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		int here_dist = pq.top().first;
		pq.pop();
		if (dist[y][x] != here_dist) continue;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nCost = arr[ny][nx];
			if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
				if (dist[ny][nx] > dist[y][x] + nCost) {
					dist[ny][nx] = dist[y][x] + nCost;
					pq.push({ dist[y][x] + nCost, {ny, nx} });
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt = 1;
	while (true) {
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				dist[i][j] = INF;
			}
		}
		solve();
		cout << "Problem " << cnt << ": " << dist[n - 1][n - 1] << "\n";
		cnt++;
	}
	return 0;
}