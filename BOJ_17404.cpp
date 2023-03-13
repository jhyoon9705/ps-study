#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, parent[100002], ret, maxVal;
struct Node {
	int from, to, val;
};
vector<Node> edge;
bool checker;

bool cmp(Node n1, Node n2) {
	return n1.val < n2.val;
}

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	checker = false;
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
	checker = true;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back({ a, b, c });
		edge.push_back({ b, a, c });
	}
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 0; i < m * 2; i++) {
		merge(edge[i].from, edge[i].to);
		if (checker) {
			ret += edge[i].val;
			maxVal = max(maxVal, edge[i].val);
		}
	}
	ret -= maxVal;
	cout << ret << "\n";
	return 0;
}