#include <bits/stdc++.h>

using namespace std;

int arr[1001][1001] = { 0, };
bool visited[1001] = { false, };
int n, m, counter = 0;
queue<int> q;

void BFS(int v) {
	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 0; i <= n; i++) {
			if (arr[v][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
	}

}

int main() {
	int u, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			BFS(i);
			counter++;
		}
	}

	cout << counter;
	
	return 0;
}