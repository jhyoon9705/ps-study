#include <bits/stdc++.h>
using namespace std;

int t, n, m, cnt, a, b;
int visited[1002];
vector<int> arr[1002];

void solve(int idx) {
	visited[idx] = 1;
	for (int nIdx : arr[idx]) {
		if (!visited[nIdx]) solve(nIdx);
	}
	return;
}

int main() {
	cin >> t;
	while (t--) {
		for (int i = 0; i < 1002; i++) {
			arr[i].clear();
		}
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			arr[b].push_back(a);
			arr[a].push_back(b);
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				solve(i);
				cnt++;
			}
		}
		if (m == n - 1 && cnt == 1) cout << "tree" << "\n";
		else cout << "graph" << "\n";
	}
	return 0;
}