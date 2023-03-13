#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, parent[102];
double x, y, ret;
struct Node {
	int from, to;
	double val;
};
vector<Node> edge;
vector<pair<int, int>> star;
bool checker = false;

double getDistance(int a, int b) {
	return sqrt(pow(abs(star[a].first - star[b].first), 2) + pow(abs(star[a].second - star[b].second), 2));
}

bool cmp(pair<int, int> s1, pair<int, int> s2) {
	if (s1.first == s2.first) return s1.second < s2.second;
	return s1.first < s2.first;
}

bool cmp2(Node n1, Node n2) {
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
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &x, &y);
		star.push_back({ x, y });
	}
	sort(star.begin(), star.end(), cmp);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			edge.push_back({ i, j, getDistance(i, j) });
		}		
	}
	sort(edge.begin(), edge.end(), cmp2);
	for (int i = 0; i < edge.size(); i++) {
		merge(edge[i].from, edge[i].to);
		if (checker) ret += edge[i].val;
	}
	printf("%.2f\n", ret);
	return 0;
}