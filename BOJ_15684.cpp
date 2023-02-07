#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, h, a, b, ret = INF;
int visited[32][32];

bool check() {
	for (int i = 1; i <= n; i++) {
		int start = i;
		for (int j = 1; j <= h; j++) {
			if (visited[j][start]) start++;
			else if (visited[j][start - 1]) start--;
		}
		if (start != i) return false;
	}
	return true;
}

void solve(int here, int cnt) {
	if (cnt > 3 || cnt >= ret) return;
	if (check()) {
		ret = min(ret, cnt);
		return;
	}
	for (int i = here; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
			visited[i][j] = 1;
			solve(i, cnt + 1);
			visited[i][j] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		visited[a][b] = 1;
	}
	solve(1, 0);
	cout << ((ret == INF) ? -1 : ret) << "\n";
	return 0;
}