#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, ret = INF;
int arr[11], comp[11], visited[11];
vector<int> adj[11];

pair<int, int> dfs(int here, int val) {
	visited[here] = 1;
	pair<int, int> ret = { 1, arr[here] };
	for (int there : adj[here]) {
		if (comp[there] != val || visited[there]) continue;
		pair<int, int> tmp = dfs(there, val);
		ret.first += tmp.first;
		ret.second += tmp.second;
	}
	return ret;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int input;
			cin >> input;
			adj[i].push_back(input);
		}
	}
	for (int i = 1; i < (1 << n) - 1; i++) {
		fill(comp, comp + 11, 0);
		fill(visited, visited + 11, 0);
		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else idx2 = j + 1;
		}
		pair<int, int> comp1 = dfs(idx1, 1);
		pair<int, int> comp2 = dfs(idx2, 0);
		if (comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second));

	}
	cout << (ret == INF ? -1 : ret) << '\n';
	return 0;
}