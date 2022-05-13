#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100][100] = { 0 };
bool visited[100] = { false };
int depth[100] = { 0 };
queue<int> q;

void BFS(int v) {
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 0; i < n; i++) {
			if (arr[v][i] == 1 && visited[i] == false) {
				visited[i] = true;
				q.push(i);
				depth[i] = depth[v] + 1; // ÃÌ¼ö °è»ê
			}
		}
	}
}

int main() {
	int tX, tY;
	cin >> n;
	cin >> tX >> tY;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		int parent, child;
		cin >> parent >> child;
		arr[parent][child] = 1;
		arr[child][parent] = 1;
	}

	BFS(tX);

	if (depth[tY] == 0) cout << -1 << endl;
	else cout << depth[tY] << endl;


}