#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> arr[2002];
int visited[2002];

void solve(int _this, int num) {
	if (num == 4) {
		cout << 1 << "\n";
		exit(0);
	}
	visited[_this] = 1;
	for (int i : arr[_this]) {
		if (!visited[i]) {
			solve(i, num + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		solve(i, 0);
	}
	cout << 0 << "\n";
	return 0;
}