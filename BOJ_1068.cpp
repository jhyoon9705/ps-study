#include <bits/stdc++.h>
using namespace std;

int n, input, idx, root, r;
vector<int> adj[51];

int solve(int here) {
	int ret = 0; // the number of leaf node
	int child = 0;
	for (int there : adj[here]) {
		if (there == r) continue; // erase
		ret += solve(there);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == -1) root = i;
		else adj[input].push_back(i);
	}
	cin >> r;
	if (r == root) cout << 0 << '\n';
	else cout << solve(root) << '\n';
	
	return 0;
}