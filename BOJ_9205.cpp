#include <bits/stdc++.h>
using namespace std;

int t, n, home_x, home_y, fest_x, fest_y;
pair<int, int> store[102];
int visited[102];
string ret;

bool solve() {
	queue<pair<int, int>> q;
	q.push({ home_x, home_y });
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		q.pop();
		if (abs(px - fest_x) + abs(py - fest_y) <= 1000) return true;
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			int dist = abs(px - store[i].first) + abs(py - store[i].second);
			if (dist <= 1000) {
				visited[i] = true;
				q.push({ store[i].first, store[i].second });
			}
		}
	}
	return false;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> home_x >> home_y;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			store[i] = { a, b };
		}
		cin >> fest_x >> fest_y;
		
		if (solve()) cout << "happy" << '\n';
		else cout << "sad" << '\n';
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}