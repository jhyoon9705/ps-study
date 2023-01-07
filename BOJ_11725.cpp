#include <bits/stdc++.h>

using namespace std;

int n;
int answer[100001];
bool visited[100001];
vector<int> graph[100001];
queue<int> q;

void BFS() {
	visited[1] = true;
	q.push(1);

	while (!q.empty()) {
		int parent = q.front();
		q.pop();

		for (int i = 0; i < (int)graph[parent].size(); i++) {
			int child = graph[parent][i];
			if (visited[child] == false) {
				answer[child] = parent;
				visited[child] = true;
				q.push(child);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int first, second;
		cin >> first >> second;
		graph[first].push_back(second);
		graph[second].push_back(first);
	}

	BFS();

	for (int i = 2; i <= n; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}