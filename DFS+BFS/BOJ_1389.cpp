#include <bits/stdc++.h>

using namespace std;

int arr[101][101];
int visited[101];
int n, m;
queue<int> q;
int minBaconNum = 9999999;

void BFS(int startNum) {
	visited[startNum] = 0;
	q.push(startNum);

	while (!q.empty()) {
		int st = q.front();
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (arr[st][i] == 1 && visited[i] == 0) { // 탐색중인 유저와 유저 i가 아는 사이면...
				visited[i] = visited[st] + 1; // 케빈 베이컨 수 계산
				q.push(i);
			}
		}
	}
}

int main() {
	int answer;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;		
	}

	for (int i = 1; i <= n; i++) { // 각 유저별 케빈 베이컨 수의 합을 계산
		memset(visited, 0, sizeof(visited));
		BFS(i);
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += (visited[j]);
		}
		
		if (sum < minBaconNum) {
			minBaconNum = sum;
			answer = i;
		}

	}

	cout << answer;
	return 0;
}