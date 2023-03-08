// ũ�罺Į
#include <bits/stdc++.h>
using namespace std;

int V, E, a, b, c, parent[10002], ret;
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
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		edge.push_back({ a, b, c });
	}
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 0; i < E; i++) {
		merge(edge[i].from, edge[i].to);
		if (checker) ret += edge[i].val;
	}
	cout << ret << "\n";
	return 0;
}