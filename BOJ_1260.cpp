#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
int N, M, V;
int graph[MAX][MAX];
bool visited[MAX] = { false };
queue<int> q;

void DFS(int index) {
	cout << index << " ";
	for (int i = 1; i <= N; i++) {
		if (graph[index][i] == 1 && !visited[i]) {
			visited[i] = true;
			DFS(i);
		}
	}
}

void BFS(int index) {
	q.push(index);
	visited[index] = 1;

	while (!q.empty()) {
		index = q.front();
		q.pop();

		cout << index << " ";

		for (int i = 1; i <= N; i++) {
			if (graph[index][i] == 1 && !visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}


int main() {
	
	cin >> N >> M >> V;


	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	visited[V] = 1;
	DFS(V);
	cout << endl;

	memset(visited, false, sizeof(visited));

	BFS(V);
	cout << endl;
}