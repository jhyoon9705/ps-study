#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr(100001);
bool visited[100001];
vector<pair<int, int>> answer;
queue<int> q;
int n, m, counter;
int maxNum = 0;

void BFS(int i) {
	while (!q.empty()) {
		int comp = q.front();
		q.pop();
		visited[comp] = true;

		for (int j = 0; j < arr[comp].size(); j++) {
			int newComp = arr[comp][j];
			if (visited[newComp] == true) continue;
			q.push(newComp);
			visited[newComp] = true;
			counter++;
		}
	}
	maxNum = max(counter, maxNum);
	answer.push_back({ i, counter });
}

int main() {
	int first, second;

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> first >> second;
		arr[second].push_back(first);
	}

	for (int i = 1; i <= n; i++) {
		counter = 0;
		memset(visited, false, sizeof(visited));
		q.push(i);
		BFS(i);
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < (int)answer.size(); i++) {
		if (answer[i].second == maxNum) {
			cout << answer[i].first << ' ';
		}
	}
	return 0;
}