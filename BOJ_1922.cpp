// 크루스칼 알고리즘
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, parent[1002], ret;
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

	if (u == v) return; // 사이클이 존재하는 경우
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
	}
	sort(edge.begin(), edge.end(), cmp);

	for (int i = 0; i < m; i++) {
		merge(edge[i].from, edge[i].to);
		if (checker) ret += edge[i].val;
	}
	cout << ret << "\n";
	return 0;
}